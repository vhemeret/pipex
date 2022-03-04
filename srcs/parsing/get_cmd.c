/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:17:38 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/04 20:07:33 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	manage_quote(t_struct *data, char c)
{
	if (c == 39)
	{
			if (data->is_quote == 0)
				data->is_quote = 1;
			else
				data->is_quote = 0;
	}
}

int	is_whithspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	nb_arg_tab(t_struct *data, char *cmd)
{
	int		i;
	int		arg;

	i = -1;
	arg = 0;
	data->is_quote = 0;
	while (cmd[++i])
	{
		manage_quote(data, cmd[i]);
		if (cmd[i + 1]
			&& ((is_whithspace(cmd[i]) && !is_whithspace(cmd[i + 1]))
			|| (!is_whithspace(cmd[i]) && i == 0))
			&& !data->is_quote)
			arg++;
	}
	return (arg);
}

int	get_cmd1(t_struct *data, char *cmd)
{
	int	size;

	size = 0;
	data->flag1 = check_if_flag(cmd);
	if (data->flag1 == 1)
	{
		data->cmd1 = extract_str(cmd, ' ');
		size = nb_arg_tab(data, cmd);
		data->cmd1_tab = malloc(sizeof(char *) * (size + 1));
		if (!data->cmd1_tab)
			return (0);
	}
	else if (data->flag1 == 0)
	{
		data->cmd1 = extract_str(cmd, ' ');
		size = 1;
		data->cmd1_tab = malloc(sizeof(char *) * (size + 1));
		if (!data->cmd1_tab)
			return (0);
	}
	if (!check_access_cmd1(data, data->cmd1))
	{
		data->cmd1_is_invalid = 1;
		data->path_cmd1 = NULL;
	}
	if (data->flag1 == 0)
	{
		data->cmd1_tab[0] = data->path_cmd1;
		data->cmd1_tab[1] = NULL;
	}
	else
	{
		data->cmd1_tab[0] = data->path_cmd1;
		put_arg_tab(data, data->cmd1_tab, extract_flag(cmd));
	}
	data->cmd1_tab[size] = NULL;
	return (1);
}

int	get_cmd2(t_struct *data, char *cmd)
{
	int	size;

	size = 0;
	data->flag2 = check_if_flag(cmd);
	if (data->flag2 == 1)
	{
		data->cmd2 = extract_str(cmd, ' ');
		size = nb_arg_tab(data, cmd);
		data->cmd2_tab = malloc(sizeof(char *) * (size + 1));
		if (!data->cmd2_tab)
			return (0);
	}
	else if (data->flag2 == 0)
	{
		data->cmd2 = extract_str(cmd, ' ');
		size = 1;
		data->cmd2_tab = malloc(sizeof(char *) * (size + 1));
		if (!data->cmd2_tab)
			return (0);
	}
	if (!check_access_cmd2(data, data->cmd2))
	{
		data->cmd2_is_invalid = 1;
		data->path_cmd2 = NULL;
	}
	if (data->flag2 == 0)
	{
		data->cmd2_tab[0] = data->path_cmd2;
		data->cmd2_tab[1] = NULL;
	}
	else
	{
		data->cmd2_tab[0] = data->path_cmd2;
		put_arg_tab(data, data->cmd2_tab, extract_flag(cmd));
	}
	data->cmd2_tab[size] = NULL;
	return (1);
}
