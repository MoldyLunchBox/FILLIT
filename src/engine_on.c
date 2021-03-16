/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_on.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 06:40:44 by amya              #+#    #+#             */
/*   Updated: 2019/06/17 18:16:19 by homadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		min_squar_size(int nb)
{
	int rc;

	rc = 1;
	nb *= 4;
	if (nb <= 0)
		return (0);
	while (rc * rc < nb)
		rc++;
	return (rc);
}

int		canput(char **square, int **shape, int i, int j)
{
	int	k;
	int	x;
	int	y;

	k = 0;
	while (k < 4)
	{
		x = shape[k][0] + j;
		y = shape[k][1] + i;
		if (x >= shape[1][2])
			return (0);
		if (y >= shape[1][2])
			return (0);
		if (square[y][x] != '.')
			return (0);
		k++;
	}
	return (1);
}

int		putshape(char **square, int **shape, int i, int j)
{
	int	k;
	int	x;
	int	y;

	k = 0;
	if (canput(square, shape, i, j) == 0)
		return (0);
	k = 0;
	while (k < 4)
	{
		x = shape[k][0] + j;
		y = shape[k][1] + i;
		square[y][x] = shape[0][2] + 'A';
		k++;
	}
	return (1);
}

int		solve(int n, char **square, int ***cords, int cur)
{
	int	i;
	int	j;

	if (cur > cords[0][0][0])
		return (1);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			cords[cur][1][2] = n;
			if (putshape(square, cords[cur], i, j))
				if (solve(n, square, cords, cur + 1))
					return (1);
			erase_shape(square, 'A' + cords[cur][0][2]);
			j++;
		}
		i++;
	}
	return (0);
}

void	engine_on(int ***cords)
{
	char	**square;
	int		n;
	int		i;
	int		j;

	top_left_corner(cords);
	n = min_squar_size(cords[0][0][0]);
	i = -1;
	square = allocate_square(n);
	while (!solve(n, square, cords, 1))
	{
		n++;
		free_2d_char(square);
		square = allocate_square(n);
	}
	while (square[++i])
	{
		j = 0;
		while (j < n)
		{
			ft_putchar(square[i][j++]);
		}
		ft_putendl("");
	}
	free_2d_char(square);
}
