/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 02:56:09 by amya              #+#    #+#             */
/*   Updated: 2019/06/17 18:13:02 by homadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	the_total(char **str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	copy(char **file, char *str)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (file[i])
	{
		j = 0;
		if ((1 + i) % 5 == 0)
		{
			str[k] = '1';
			i++;
			k++;
		}
		while (file[i][j])
		{
			str[k] = file[i][j];
			j++;
			k++;
		}
		i++;
	}
}

char		*one_line(char **file)
{
	char	*str;
	int		total;

	total = the_total(file);
	str = malloc(sizeof(char) * ((total - (total % 4)) * 4) + (total % 4) + 1);
	ft_bzero(str, (((total - (total % 4)) * 4) + (total % 4) + 1));
	copy(file, str);
	free_2d_char(file);
	return (str);
}
