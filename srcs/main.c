/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:58:55 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/21 06:59:50 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **env)
{
	t_struct	*data;

	data = malloc(sizeof(t_struct));
	if (!data)
		return (0);
	if (!check_error(ac, av, env, data))
	{
		free(data);
		return (0);
	}
	if (!pipex(data, env))
	{
		cleaning(data);
		return (0);
	}
	cleaning(data);
	return (0);
}
