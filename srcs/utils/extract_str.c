/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:27:41 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/23 07:04:48 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	check_space(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		if (str[i] == ' ')
			while (str[i] && str[i] == ' ')
				i++;
		if (str[i] == '\0')
			return (-1);
		else
			return (i);
	}
	else
		return (-1);
}

char	*malloc_cmd(char *cmd, int size)
{
	cmd = malloc(sizeof(char) * (size + 1));
	if (!cmd)
		return (NULL);
	return (cmd);
}

char	*extract_str(char *str, int to_find)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	*dst;

	size = 0;
	dst = NULL;
	i = check_space(str);
	k = 0;
	if (i == -1)
		return (NULL);
	j = i;
	while (str[i] != (char)to_find && str[i])
	{
		i++;
		size++;
	}
	dst = malloc_cmd(dst, size);
	j -= 1;
	while (str[++j] != (char)to_find && str[j])
		dst[k++] = str[j];
	dst[k] = '\0';
	return (dst);
}
