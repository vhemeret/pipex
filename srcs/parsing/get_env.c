/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:38:54 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/16 17:41:59 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	get_env(char **env, t_struct *data)
{
	int		i;
	char	*path;

	i = -1;
	while (env[++i])
	{
		path = to_find(env[i], "PATH=");
		if (path != NULL)
		{
			data->envp = ft_split(path, ':');
			return (1);
		}
	}
	return (0);
}
