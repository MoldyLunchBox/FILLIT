/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_leak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 04:44:38 by amya              #+#    #+#             */
/*   Updated: 2019/06/17 18:12:24 by homadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	free_2d_char(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_3d_int(int ***array)
{
	int i;
	int j;

	i = 1;
	while (i <= array[0][0][0])
	{
		j = 0;
		while (j < 4)
		{
			free(array[i][j]);
			j++;
		}
		free(array[i]);
		i++;
	}
	free(array[0][0]);
	free(array[0]);
	free(array);
}
