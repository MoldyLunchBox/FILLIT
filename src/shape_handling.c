/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 21:45:39 by amya              #+#    #+#             */
/*   Updated: 2019/06/17 18:13:22 by homadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	erase_shape_alt(char **square, char c)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = -1;
	while (square[1 + i] && i++ >= -2 && (j = -1))
		while (square[i][1 + j] && j++ > -2)
			if (square[i][j] == c)
			{
				if (k)
					square[i][j] = '.';
				k = 1;
			}
}

void	erase_shape(char **square, char c)
{
	int	i;
	int	j;

	i = -1;
	while (square[1 + i] && i++ >= -2 && (j = -1))
		while (square[i][1 + j] && j++ > -2)
			if (square[i][j] == c)
				square[i][j] = '.';
}

void	put_down_shape(char **square, int i, int j, int **shape)
{
	square[i + shape[0][1]][j + shape[0][0]] = 'A' + shape[0][2];
	square[i + shape[1][1]][j + shape[1][0]] = 'A' + shape[0][2];
	square[i + shape[2][1]][j + shape[2][0]] = 'A' + shape[0][2];
	square[i + shape[3][1]][j + shape[3][0]] = 'A' + shape[0][2];
	j = 0;
}
