/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 21:21:39 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/09/04 16:32:10 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	warm_map_init(t_map *map)
{
	int y;
	int x;

	y = 0;
	while (y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			map->warm_map[y][x] = 10000;
			map->cold_map[y][x] = 10000;
		}
		y++;
	}
}

void	print_result(t_map *map)
{
	ft_putnbr(map->ret_y);
	ft_putchar(' ');
	ft_putnbr(map->ret_x);
	ft_putchar('\n');
}

void	del_piece(t_map *map)
{
	int y;

	y = -1;
	if (map->piece)
		while (++y < map->h_p)
		{
			if (map->piece[y])
				ft_strdel(&(map->piece[y]));
		}
	if (map->piece)
		free(map->piece);
	map->piece = NULL;
	y = -1;
	if (map->field)
		while (++y < map->height)
		{
			if (map->field[y])
				ft_strdel(&(map->field[y]));
		}
}

void	count_piece_size(char *str, t_map *map)
{
	int i;

	i = 0;
	map->h_p = ft_atoi(str + 6);
	while (ft_isdigit(*(str + 6 + i)))
		i++;
	map->w_p = ft_atoi(str + i + 6);
	map->piece = (char**)malloc(sizeof(char*) * map->h_p);
	ft_strdel(&str);
}

void	set_values(t_map *map, int x, int y, int warm)
{
	map->warm = warm;
	map->ret_y = y;
	map->ret_x = x;
}
