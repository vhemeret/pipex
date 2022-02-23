/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:26:06 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/21 06:58:02 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	check_directory(char *path_file, int file)
{
	int	fd;

	fd = open(path_file, __O_DIRECTORY);
	if (fd == -1)
		return (1);
	close(fd);
	if (file == 1)
		ft_putstr_fd("Error:\nfile 1 is a directory.\n", 1);
	else
		ft_putstr_fd("Error:\nfile 2 is a directory.\n", 1);
	return (0);
}

int	check_file1(char *path_file)
{
	int	fd;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error:\nfile 1 does not exist.\n", 1));
	close(fd);
	return (1);
}

int	check_file2(t_struct *data)
{
	data->outfile = open(data->file2, O_RDWR | O_TRUNC);
	if (data->outfile == -1)
	{
		if (access(data->file2, F_OK))
		{
			data->outfile = open(data->file2, O_RDWR | O_CREAT, 0644);
			if (data->outfile == -1)
				return (ft_putstr_fd("Error:\nFailed to create outfile\n", 1));
		}
		else
			return (ft_putstr_fd("Error:\nThe path is corrupted\n", 1));
	}
	return (1);
}
