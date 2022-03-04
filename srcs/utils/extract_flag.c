/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:20:08 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/04 17:57:16 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*extract_flag(char *cmd)
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
			return (&cmd[i]);
		}
	}
	else if (cmd[i] != ' ' && cmd[i])
	{
		while (cmd[i] != ' ' && cmd[i])
			i++;
		return (&cmd[i]);
	}
	return (NULL);
}
