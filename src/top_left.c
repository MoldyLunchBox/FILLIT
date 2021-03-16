/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 10:04:42 by amya              #+#    #+#             */
/*   Updated: 2019/06/17 18:20:26 by homadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		*top_left(int **cords)
{
	int		top_y;
	int		left_x;
	int		*top_left;
	int		i;

	i = 0;
	left_x = cords[0][0];
	top_y = cords[0][1];
	while (i < 3)
	{
		if (left_x > cords[1 + i][0])
			left_x = cords[1 + i][0];
		if (top_y > cords[1 + i][1])
			top_y = cords[1 + i][1];
		i++;
	}
	top_left = malloc(sizeof(int) * 3);
	top_left[0] = left_x;
	top_left[1] = top_y;
	i = 0;
	return (top_left);
}

void	top_left_corner(int ***cords)
{
	int	i;
	int	j;
	int	*ttop_left;

	i = 1;
	j = 0;
	while (i <= cords[0][0][0])
	{
		ttop_left = top_left(cords[i]);
		j = 0;
		while (j < 4)
		{
			cords[i][j][0] = cords[i][j][0] - ttop_left[0];
			cords[i][j][1] = cords[i][j][1] - ttop_left[1];
			j++;
		}
		free(ttop_left);
		i++;
	}
}
