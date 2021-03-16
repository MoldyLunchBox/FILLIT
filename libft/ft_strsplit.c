/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:55:35 by homadani          #+#    #+#             */
/*   Updated: 2019/06/13 10:23:45 by homadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrmot(char *str, char c)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (str[i - 1] != c)
				count++;
		}
		i++;
	}
	count++;
	return (count);
}

static int		ft_nbrcar(char *str, char c)
{
	size_t count;
	size_t i;

	count = 0;
	i = ft_strlen(str);
	while (str[i])
	{
		if (str[i] != c)
			count++;
		else
			break ;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	if (!(s && (tab = (char **)malloc(sizeof(char *) *
						(ft_nbrmot((char *)s, c) + 1)))))
		return (NULL);
	while (s[i])
	{
		i = (int)ft_skipchar((char *)s, c, i);
		if (s[i])
		{
			k = 0;
			if (!(tab[j] = ft_strnew(ft_nbrcar((char *)s, c))))
				return (NULL);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
