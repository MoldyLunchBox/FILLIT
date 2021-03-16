/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amya <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:43:29 by amya              #+#    #+#             */
/*   Updated: 2019/06/18 16:56:11 by amya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/get_next_line.h"
# include "../libft/libft.h"

int					call_error(int ac, char *str);
char				**allocate_square(int size);
char				*one_line(char **line);
typedef struct		s_verify
{
	int i;
	int j;
	int d;
	int c;
}					t_verify;
void				free_2d_char(char **str);
int					min_square_size(int nb);
int					***cord(char **str);
int					num_of_shapes(char **str);
void				original_position(int ***cords);
void				ft_putchar(char c);
void				erase_shape(char **square, char c);
void				top_left_corner(int ***cords);
void				put_down_shape(char **square, int i, int j, int **shape);
void				free_3d_int(int ***array);
void				engine_on(int ***shape);
void				max_shapes_check(int nbr);
#endif
