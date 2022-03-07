/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 03:29:40 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/07 18:57:04 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static char	*alloc_and_put_into_quote(char *cmd)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	while (cmd[i] && cmd[i] != 39)
		i++;
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (cmd[i] && cmd[i] != 39)
	{
		tab[j] = cmd[i];
		j++;
		i++;
	}
	tab[j] = '\0';
	return (tab);
}

static char	*alloc_and_put(char *cmd)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	while ((cmd[i] < 9 || cmd[i] > 13) && cmd[i] != ' ')
		i++;
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while ((cmd[i] < 9 || cmd[i] > 13) && cmd[i] != ' ')
	{
		tab[j] = cmd[i];
		j++;
		i++;
	}
	tab[j] = '\0';
	return (tab);
}

void	put_arg_tab(t_struct *data, char **tab, char *cmd, int tab_index)
{
	int	i;

	i = -1;
	data->is_quote = 0;
	while (cmd[++i])
	{
		if (cmd[i] == 39)
			manage_quote(data, cmd[i]);
		else if (((cmd[i] < 9 || cmd[i] > 13) && cmd[i] != ' ')
			&& data->is_quote == 0 && cmd[i])
		{
			tab[tab_index++] = alloc_and_put(&cmd[i]);
			while ((cmd[i] < 9 || cmd[i] > 13) && cmd[i] != ' ' && cmd[i])
				i++;
			i -= 1;
		}
		else if (data->is_quote == 1)
		{
			tab[tab_index++] = alloc_and_put_into_quote(&cmd[i]);
			while (cmd[i] && cmd[i] != 39)
				i++;
			i -= 1;
		}
	}
}
