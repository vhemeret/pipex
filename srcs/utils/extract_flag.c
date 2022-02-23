/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:20:08 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/23 04:24:19 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static char	*malloc_flag(char *dst, int size)
{
	dst = malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	return (dst);
}

static int	until_flag(char *cmd, int to_find)
{
	int	i;

	i = 0;
	if (cmd[i] && cmd[i] == ' ')
	{
		while (cmd[i] && cmd[i] == (char)to_find)
			i++;
		while (cmd[i] && cmd[i] != (char)to_find)
			i++;
		while (cmd[i] && cmd[i] == (char)to_find)
			i++;
		return (i);
	}
	else
	{
		while (cmd[i] && cmd[i] != (char)to_find)
			i++;
		while (cmd[i] && cmd[i] == (char)to_find)
			i++;
		return (i);
	}
}

char	*extract_flag(char *cmd, int to_find)
{
	int		i;
	int		j;
	int		size;
	char	*dst;

	dst = NULL;
	i = until_flag(cmd, to_find);
	j = i;
	size = 0;
	while (cmd[j] && cmd[j] != (char)to_find)
	{
		j++;
		size++;
	}
	dst = malloc_flag(dst, size);
	j = i;
	i = 0;
	while (cmd[j] && cmd[j] != (char)to_find)
	{
		dst[i] = cmd[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
