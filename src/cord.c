/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:34:31 by amya              #+#    #+#             */
/*   Updated: 2019/06/17 18:11:52 by homadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		***alloc_3d(int nb_of_shapes)
{
	int ***cords;
	int i;
	int j;

	i = 1;
	cords = (int ***)malloc(sizeof(int **) * (nb_of_shapes + 1));
	cords[0] = (int **)malloc(sizeof(int *));
	cords[0][0] = malloc(sizeof(int));
	cords[0][0][0] = nb_of_shapes;
	while (i <= nb_of_shapes)
	{
		cords[i] = (int **)malloc(sizeof(int *) * 4);
		j = 0;
		while (j < 4)
		{
			cords[i][j] = malloc(sizeof(int) * 3);
			j++;
		}
		i++;
	}
	return (cords);
}

int		*set_cords(int *cord, int x, int y, int alpha)
{
	cord[0] = x;
	cord[1] = y;
	cord[2] = alpha;
	return (cord);
}

int		***cord(char **str)
{
	int i;
	int j;
	int k;
	int ***cords;

	i = 0;
	cords = alloc_3d(num_of_shapes(str));
	while (str[i])
	{
		j = 0;
		k = 0;
		while (str[i][j])
		{
			if (str[i][j] == '#')
			{
				cords[1 + i][k] = set_cords(cords[1 + i][k], j % 4, j / 4, i);
				k++;
			}
			j++;
		}
		i++;
	}
	return (cords);
}
