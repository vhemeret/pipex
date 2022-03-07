/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:17:38 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/07 17:27:20 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	check_access_cmd(t_struct *data, char *cmd1, char *cmd2)
{
	data->flag1 = check_if_flag(cmd1);
	data->flag2 = check_if_flag(cmd2);
	data->cmd1 = extract_str(cmd1, ' ');
	data->cmd2 = extract_str(cmd2, ' ');
	if (!check_access_cmd1(data, data->cmd1))
	{
		data->cmd1_is_invalid = 1;
		data->path_cmd1 = NULL;
	}
	if (!check_access_cmd2(data, data->cmd2))
	{
		data->cmd2_is_invalid = 1;
		data->path_cmd2 = NULL;
	}
	get_cmd1(data, cmd1);
	get_cmd2(data, cmd2);
}

int	get_cmd1(t_struct *data, char *cmd)
{
	int	size;

	size = 0;
	if (data->flag1 == 1 && data->cmd1_is_invalid == 0)
	{
		size = nb_arg_tab(data, cmd);
		data->cmd1_tab = malloc(sizeof(char *) * (size + 1));
		if (!data->cmd1_tab)
			return (0);
		data->cmd1_tab[0] = data->path_cmd1;
		put_arg_tab(data, data->cmd1_tab, extract_flag(cmd));
	}
	else
	{
		size = 1;
		data->cmd1_tab = malloc(sizeof(char *) * (size + 1));
		if (!data->cmd1_tab)
			return (0);
		data->cmd1_tab[0] = data->path_cmd1;
		data->cmd1_tab[1] = NULL;
	}
	data->cmd1_tab[size] = NULL;
	return (0);
}

int	get_cmd2(t_struct *data, char *cmd)
{
	int	size;

	size = 0;
	if (data->flag2 == 1 && data->cmd2_is_invalid == 0)
	{
		size = nb_arg_tab(data, cmd);
		data->cmd2_tab = malloc(sizeof(char *) * (size + 1));
		if (!data->cmd2_tab)
			return (0);
		data->cmd2_tab[0] = data->path_cmd2;
		put_arg_tab(data, data->cmd2_tab, extract_flag(cmd));
	}
	else
	{
		size = 1;
		data->cmd2_tab = malloc(sizeof(char *) * (size + 1));
		if (!data->cmd2_tab)
			return (0);
		data->cmd2_tab[0] = data->path_cmd2;
		data->cmd2_tab[1] = NULL;
	}
	data->cmd2_tab[size] = NULL;
	return (0);
}
