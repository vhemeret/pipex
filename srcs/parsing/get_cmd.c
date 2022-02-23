/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:17:38 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/23 06:57:26 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	malloc_arg_tab(t_struct *data)
{
	data->cmd1_tab = malloc(sizeof(char *) * (3));
	if (!data->cmd1_tab)
		return ;
	data->cmd2_tab = malloc(sizeof(char *) * (3));
	if (!data->cmd2_tab)
		return ;
}

int	get_cmd1(t_struct *data, char *cmd)
{
	data->flag1 = check_if_flag(cmd);
	if (data->flag1 == 1)
	{
		data->cmd1 = extract_str(cmd, ' ');
		data->cmd1_flag = extract_flag(cmd, ' ');
	}
	else if (data->flag1 == 0)
	{
		data->cmd1_flag = NULL;
		data->cmd1 = extract_str(cmd, ' ');
	}
	if (!check_access_cmd1(data, data->cmd1))
	{
		data->cmd1_is_invalid = 1;
		if (data->flag1 == 1)
		{
			free(data->cmd1_flag);
			data->cmd1_flag = NULL;
		}
		data->path_cmd1 = NULL;
	}
	data->cmd1_tab[0] = data->path_cmd1;
	data->cmd1_tab[1] = data->cmd1_flag;
	data->cmd1_tab[2] = NULL;
	return (1);
}

int	get_cmd2(t_struct *data, char *cmd)
{
	data->flag2 = check_if_flag(cmd);
	if (data->flag2 == 1)
	{
		data->cmd2_flag = extract_flag(cmd, ' ');
		data->cmd2 = extract_str(cmd, ' ');
	}
	else if (data->flag2 == 0)
	{
		data->cmd2_flag = NULL;
		data->cmd2 = extract_str(cmd, ' ');
	}
	if (!check_access_cmd2(data, data->cmd2))
	{
		data->cmd2_is_invalid = 1;
		data->path_cmd2 = NULL;
		if (data->flag2 == 1)
		{
			free(data->cmd2_flag);
			data->cmd2_flag = NULL;
		}
	}
	data->cmd2_tab[0] = data->path_cmd2;
	data->cmd2_tab[1] = data->cmd2_flag;
	data->cmd2_tab[2] = NULL;
	return (1);
}
