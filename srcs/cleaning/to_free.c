/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:27:58 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/07 22:04:05 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	**free_double_tab(char **tab)
{
	int	i;
	int	nb_elem;

	i = -1;
	nb_elem = 0;
	if (tab)
	{
		while (tab[nb_elem])
			nb_elem++;
		if (nb_elem)
		{
			while (++i <= nb_elem)
			{
				if (tab[i])
				{
					free(tab[i]);
					tab[i] = NULL;
				}
			}
		}
	}
	free(tab);
	tab = NULL;
	return (tab);
}

int	free_str(char *str)
{
	free(str);
	return (0);
}

void	cleaning(t_struct *data)
{
	free_double_tab(data->envp);
	if (data->cmd1_is_invalid == 0)
		free_double_tab(data->cmd1_tab);
	else
		free(data->cmd1_tab);
	if (data->cmd2_is_invalid == 0)
		free_double_tab(data->cmd2_tab);
	else
		free(data->cmd2_tab);
	if (data->cmd1_is_path == 0)
	{
		free(data->cmd1);
		data->cmd1 = NULL;
	}
	if (data->cmd2_is_path == 0)
	{
		free(data->cmd2);
		data->cmd2 = NULL;
	}
	free(data);
}
