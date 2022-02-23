/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:58:11 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/08 16:05:32 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	is_sep(char s, char c)
{
	if (s == c)
		return (0);
	return (1);
}

int	nb_words(char const *s, char c)
{
	int	word;
	int	i;

	i = -1;
	word = 0;
	while (s[++i])
		if (is_sep((char)s[i], c) && (i == 0 || !is_sep((char)s[i - 1], c)))
			word++;
	return (word);
}

char	*put_in_tab(char const *s, char c)
{
	char		*tab;
	int			i;
	static int	count;

	i = 0;
	count = 0;
	while (s[i] && is_sep((char)s[i], c))
		i++;
	tab = malloc(sizeof(*tab) * (i + 1));
	if (!tab)
		return (NULL);
	count++;
	i = -1;
	while (s[++i] && is_sep((char)s[i], c))
		tab[i] = s[i];
	tab[i] = '\0';
	return (tab);
}

char	**__free_split__(char **to_free, int nb_elem)
{
	int	i;

	i = -1;
	if (nb_elem)
	{
		while (++i < nb_elem)
		{
			free(to_free[i]);
			to_free[i] = NULL;
		}
	}
	free(to_free);
	to_free = NULL;
	return (to_free);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word;
	int		i;

	word = 0;
	i = -1;
	if (!s || s[1] == '\0' || s[0] == '\0')
		return (NULL);
	tab = malloc(sizeof(*tab) * (nb_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[++i] && word < nb_words(s, c))
	{
		if (is_sep(s[i], c) && (i == 0 || !is_sep(s[i - 1], c)))
		{
			tab[word] = put_in_tab(&s[i], c);
			if (tab[word] == NULL)
				return (__free_split__(tab, word));
			word++;
		}
	}
	tab[word] = NULL;
	return (tab);
}
