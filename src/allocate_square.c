/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 09:57:45 by amya              #+#    #+#             */
/*   Updated: 2019/06/17 18:11:05 by homadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**allocate_square(int size)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		tab[i] = (char *)malloc(sizeof(char) * size + 1);
		tab[i][size + 1] = '\0';
		ft_memset(tab[i], '.', size);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
