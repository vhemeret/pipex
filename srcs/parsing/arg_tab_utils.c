/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_tab_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:00:57 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/07 17:28:57 by vahemere         ###   ########.fr       */
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

int	nb_arg_tab(t_struct *data, char *cmd)
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
