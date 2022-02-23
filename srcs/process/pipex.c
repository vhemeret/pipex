/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:02:30 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/23 06:06:21 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static int	manage_child1(t_struct *data, char **envp)
{
	close(data->pipefd[0]);
	if (!check_directory(data->file1, 1) || !check_file1(data->file1))
		return (0);
	data->infile = open(data->file1, O_RDONLY);
	if (data->infile == -1)
		return (0);
	if (dup2(data->infile, STDIN_FILENO) == -1)
		return (ft_putstr_fd("Error:\ndup2 infile, stdin failed.\n", 2));
	if (dup2(data->pipefd[1], STDOUT_FILENO) == -1)
		return (ft_putstr_fd("Error:\ndup2 pipefd[1], stdout failed.\n", 2));
	close(data->pipefd[1]);
	if (!data->cmd1_tab[0])
	{
		close(data->infile);
		return (ft_putstr_fd("Error:\nCommand 1 not found.\n", 2));
	}
	if (execve(data->path_cmd1, data->cmd1_tab, envp) == -1)
	{
		close(data->infile);
		return (ft_putstr_fd("Error:\nCommand 1 not found.\n", 2));
	}
	return (1);
}

static int	manage_child2(t_struct *data, char **envp)
{
	close(data->pipefd[1]);
	if (!check_directory(data->file2, 2) || !check_file2(data))
		return (0);
	if (dup2(data->pipefd[0], STDIN_FILENO) == -1)
		return (ft_putstr_fd("Error:\ndup2 pipefd[0], stdin failed.\n", 2));
	close(data->pipefd[0]);
	if (dup2(data->outfile, STDOUT_FILENO) == -1)
		return (ft_putstr_fd("Error:\ndup2 outfile, stdout failed.\n", 2));
	if (!data->cmd2_tab[0])
	{
		close(data->outfile);
		return (ft_putstr_fd("Error:\nCommand 2 not found.\n", 2));
	}
	if (execve(data->path_cmd2, data->cmd2_tab, envp) == -1)
	{
		close(data->outfile);
		return (ft_putstr_fd("Error:\nCommand 2 not found.\n", 2));
	}
	return (1);
}

int	check_child_id(int id, int child)
{
	if (id < 0 && child == 1)
	{
		ft_putstr_fd("Error:\nfork child 1 failed.\n", 1);
		return (0);
	}
	if (id < 0 && child == 2)
	{
		ft_putstr_fd("Error:\nfork child 2 failed.\n", 1);
		return (0);
	}
	return (1);
}

void	close_and_wait(t_struct *data, int status)
{
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	waitpid(data->child1, &status, 0);
	waitpid(data->child2, &status, 0);
}

int	pipex(t_struct *data, char **envp)
{
	int	status;

	status = 0;
	if (pipe(data->pipefd) < 0)
		return (ft_putstr_fd("Error:\nCreation pipe failed.\n", 1));
	data->child1 = fork();
	if (!check_child_id(data->child1, 1))
		return (0);
	else if (data->child1 == 0)
	{
		if (!manage_child1(data, envp))
			return (0);
		close(data->infile);
	}
	data->child2 = fork();
	if (!check_child_id(data->child2, 2))
		return (0);
	else if (data->child2 == 0)
	{
		if (!manage_child2(data, envp))
			return (0);
		close(data->outfile);
	}
	close_and_wait(data, status);
	return (1);
}
