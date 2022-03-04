/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:52:32 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/16 16:44:58 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*to_find(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == to_find[j])
	{
		while (str[i] == to_find[j] && str[i] && to_find[j])
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
			return (&str[i]);
	}
	return (NULL);
}
