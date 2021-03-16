/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:35:36 by amya              #+#    #+#             */
/*   Updated: 2019/06/18 16:49:49 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	string_alloc(char **string, char **str)
{
	int i;
	int j;

	i = 0;
	while (string[i])
	{
		str[i] = malloc(sizeof(char) * (ft_strlen(string[i]) + 1));
		ft_bzero(str[i], ft_strlen(string[i]) + 1);
		j = 0;
		while (string[i][j])
		{
			str[i][j] = string[i][j];
			j++;
		}
		i++;
	}
}

char	**file(char **string, char *line)
{
	int		i;
	char	**str;
	int		j;

	i = 0;
	j = 0;
	while (string[i])
		i++;
	str = (char **)malloc(sizeof(char *) * (i + 2));
	string_alloc(string, str);
	free_2d_char(string);
	str[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
	ft_bzero(str[i], ft_strlen(line) + 1);
	while (line[j])
	{
		str[i][j] = line[j];
		j++;
	}
	str[i + 1] = NULL;
	free(line);
	return (str);
}

int		nb_connection(char **str, t_verify *ver)
{
	if (str[ver->i][ver->j] != '.' && str[ver->i][ver->j] != '#')
		return (0);
	if (ver->i % 5 != 0 && str[ver->i][ver->j]
			== '#' && str[ver->i - 1][ver->j] == '#')
		ver->c += 2;
	if (str[ver->i][ver->j] == '#'
			&& str[ver->i][ver->j + 1] == '#')
		ver->c += 2;
	if (str[ver->i][ver->j] == '#')
		ver->d++;
	if ((ver->j != 4 && str[ver->i][ver->j] == '\0'))
		return (0);
	return (ver->d);
}

int		verify(char **str)
{
	t_verify ver;

	ver.i = -1;
	while (str[++ver.i])
	{
		if (!(ver.j = 0) && (ver.i == 0 || (ver.i + 1) % 5 == 0))
		{
			if (ver.i != 0 && ((ver.c != 6 && ver.c != 8)
						|| ver.d != 4 || str[ver.i][0] != '\0'))
				return (0);
			ver.c = 0;
			ver.d = 0;
			if (ver.i && str[1 + ver.i])
				ver.i++;
		}
		while (str[ver.i][ver.j])
		{
			ver.d = nb_connection(str, &ver);
			ver.j++;
		}
		if (ver.j != 4 && ((1 + ver.i) % 5 != 0))
			return (0);
	}
	return (ver.d == 4 && (ver.c == 6 || ver.c == 8));
}

int		main(int ac, char **av)
{
	char	*line;
	char	**str;
	int		fd;
	int		***str2;

	if (!(call_error(ac, av[1])))
		return (0);
	str = (char **)malloc(sizeof(char *));
	str[0] = NULL;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
		str = file(str, line);
	if (!verify(str))
	{
		ft_putendl("error");
		return (0);
	}
	line = one_line(str);
	str = ft_split4fil(line, '1');
	max_shapes_check(num_of_shapes(str));
	free(line);
	str2 = cord(str);
	free_2d_char(str);
	engine_on(str2);
	free_3d_int(str2);
}
