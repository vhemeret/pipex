/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:35:34 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/04 20:28:58 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	check_error(int ac, char **av, char **env, t_struct *data)
{
	data->file1 = av[1];
	data->file2 = av[4];
	data->cmd1 = av[2];
	data->cmd2 = av[3];
	if (ac != 5)
		return (ft_putstr_fd("Error:\nTo few arguments.\n", 1));
	if (!get_env(env, data))
	{
		free_double_tab(data->envp);
		return (ft_putstr_fd("Error:\nThe environment is corrupted.\n", 1));
	}
	get_cmd1(data, data->cmd1);
	get_cmd2(data, data->cmd2);
	return (1);
}
