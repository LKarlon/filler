/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:16:28 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/09/04 16:29:23 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	player_init(t_map *map)
{
	char	*str;

	get_next_line(0, &str);
	if (ft_strstr(str, "p1"))
	{
		map->pl = 'O';
		map->pl2 = 'X';
	}
	else
	{
		map->pl = 'X';
		map->pl2 = 'O';
	}
	free(str);
}

t_map	*map_init(void)
{
	t_map	*map;
	char	*str;
	int		i;

	i = 8;
	map = (t_map*)malloc(sizeof(t_map));
	player_init(map);
	get_next_line(0, &str);
	map->height = ft_atoi(str + i);
	while (ft_isdigit(*(str + i)))
		i++;
	map->width = ft_atoi(str + i);
	free(str);
	map->field = (char**)malloc(sizeof(char*) * map->height);
	map->warm_map = (int**)malloc(sizeof(int*) * map->height);
	map->cold_map = (int**)malloc(sizeof(int*) * map->height);
	i = 0;
	while (i < map->height)
	{
		map->cold_map[i] = (int*)malloc(sizeof(int) * map->width);
		map->warm_map[i++] = (int*)malloc(sizeof(int) * map->width);
	}
	return (map);
}

void	put_piece(t_map *map)
{
	int y;
	int x;
	int flag;

	y = -1;
	x = 0;
	flag = 1;
	map->warm = 0;
	while (flag && ++y <= (map->height - map->h_p) && (x = -1))
		while (flag && ++x <= (map->width - map->w_p))
			if (map->field[y][x] == map->pl)
			{
				((x - map->w_p) < 0) ? x = 0 : (x -= map->w_p);
				((y - map->h_p) < 0) ? y = 0 : (y -= map->h_p);
				flag = 0;
			}
	while (y <= (map->height - map->h_p))
	{
		while (++x <= (map->width - map->w_p))
			warmer(y, x, map);
		x = -1;
		y++;
	}
	print_result(map);
}

void	map_make(t_map *map)
{
	char	*str;
	int		i;

	i = -1;
	warm_map_init(map);
	while (get_next_line(0, &str))
	{
		if (ft_isdigit(*str))
			map->field[++i] = ft_strcccpy(str + 4, '\n');
		if (ft_strstr(str, "Piece") && (i = -1))
		{
			count_piece_size(str, map);
			while (++i < (map->h_p) && get_next_line(0, &str))
			{
				map->piece[i] = ft_strcccpy(str, '\n');
				ft_strdel(&str);
			}
			warm_map(map, -1, -1);
			put_piece(map);
			del_piece(map);
			i = -1;
		}
		if (str)
			ft_strdel(&str);
	}
}

int		main(void)
{
	t_map	*map;

	map = map_init();
	map_make(map);
}
