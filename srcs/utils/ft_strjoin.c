/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:46:47 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/19 04:00:29 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*ft_strjoin(char *path, char *cmd)
{
	int		i;
	int		j;
	char	*dst;

	i = -1;
	dst = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmd) + 2));
	if (!dst)
		return (NULL);
	while (path[++i])
		dst[i] = path[i];
	dst[i] = '/';
	j = -1;
	while (cmd[++j])
		dst[++i] = cmd[j];
	dst[i + 1] = '\0';
	return (dst);
}
