/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 18:08:47 by homadani          #+#    #+#             */
/*   Updated: 2019/06/18 16:55:25 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	max_shapes_check(int nbr)
{
	if (nbr > 26)
	{
		ft_putendl("error");
		exit(0);
	}
}

int		call_error(int ac, char *str)
{
	int fd;

	if (ac != 2)
	{
		ft_putstr("usage: fillit [file_name]\n");
		return (0);
	}
	if ((fd = open(str, O_RDONLY)) < 0)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}
