/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:17:14 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/07 22:18:03 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	get_absolute_path(t_struct *data, char *cmd, int index)
{
	int		i;
	int		fd;
	char	*path_cmd;

	i = -1;
	path_cmd = NULL;
	if (cmd)
	{
		while (data->envp[++i])
		{
			path_cmd = ft_strjoin(data->envp[i], cmd);
			fd = access(path_cmd, F_OK);
			if (fd == 0)
			{
				if (index == 1)
					data->path_cmd1 = path_cmd;
				else if (index == 2)
					data->path_cmd2 = path_cmd;
				return (1);
			}
			free(path_cmd);
			path_cmd = NULL;
		}
	}
	return (0);
}

int	check_absolute_path(t_struct *data, char *cmd, int index)
{
	int		fd;

	if (cmd)
	{
		fd = access(cmd, F_OK);
		if (fd == 0)
		{
			if (index == 1)
				data->path_cmd1 = cmd;
			else if (index == 2)
				data->path_cmd2 = cmd;
			return (1);
		}
	}
	return (0);
}

static int	check_if_flag2(char *cmd)
{
	int	i;

	i = 0;
	if (cmd[i] != ' ' && cmd[i])
	{
		while (cmd[i] != ' ' && cmd[i])
			i++;
		if (cmd[i] == ' ' && cmd[i])
		{
			while (cmd[i] == ' ' && cmd[i])
				i++;
			if (cmd[i] && cmd[i] != ' ')
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

int	check_if_flag(char *cmd)
{
	int	i;

	i = 0;
	if (cmd[i] == ' ')
	{
		while (cmd[i] == ' ' && cmd[i])
			i++;
		if (cmd[i] != ' ' && cmd[i])
		{
			while (cmd[i] != ' ' && cmd[i])
				i++;
			if (cmd[i] == ' ' && cmd[i])
			{
				while (cmd[i] == ' ' && cmd[i])
					i++;
				if (cmd[i] && cmd[i] != ' ')
					return (1);
				else
					return (0);
			}
		}
	}
	else
		return (check_if_flag2(cmd));
	return (0);
}
