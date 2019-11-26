/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_warm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:03:02 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/09/04 16:31:45 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	warmer(int y, int x, t_map *map)
{
	int yp;
	int xp;
	int count;
	int warm;

	count = 0;
	yp = -1;
	warm = 0;
	while (++yp < map->h_p && (xp = -1))
		while (++xp < map->w_p)
		{
			if (map->piece[yp][xp] == '*')
				warm += map->cold_map[y + yp][x + xp];
			if (map->piece[yp][xp] == '*' && map->field[y + yp][x + xp]
					== map->pl)
				count++;
			if (((map->piece[yp][xp] == '*') && (map->field[y + yp][x + xp] ==
					map->pl2)) || count > 1)
				return ;
		}
	if (count == 0)
		return ;
	if (map->warm > warm || !map->warm)
		set_values(map, x, y, warm);
}

void	count_digit(int y, int x, t_map *map, int fl)
{
	int w;
	int h;

	h = -2;
	while (++h < 2 && (w = -2))
	{
		if (y + h < 0 || y + h >= map->height)
			continue;
		while (++w < 2)
		{
			if (x + w < 0 || x + w >= map->width)
				continue;
			if (fl == 1)
			{
				if (map->warm_map[y + h][x + w] > map->warm_map[y][x])
					map->warm_map[y + h][x + w] = map->warm_map[y][x] + 1;
			}
			else if (fl == 2)
			{
				if (map->cold_map[y + h][x + w] > map->cold_map[y][x])
					map->cold_map[y + h][x + w] = map->cold_map[y][x] + 1;
			}
		}
	}
}

void	make_warm_map(t_map *map, int y, int x)
{
	int warm_flag;
	int cold_flag;
	int i;

	warm_flag = 1;
	cold_flag = 1;
	i = 0;
	while ((warm_flag == 1 || cold_flag == 1) && (y = -1) && i++ < map->width)
	{
		while (++y < map->height && (x = -1))
			while (++x < map->width)
			{
				if (warm_flag && map->warm_map[y][x] == 10000)
					warm_flag = 2;
				else if (warm_flag && map->warm_map[y][x] >= 0)
					count_digit(y, x, map, 1);
				if (cold_flag && map->cold_map[y][x] == 10000)
					cold_flag = 2;
				else if (cold_flag && map->cold_map[y][x] >= 0)
					count_digit(y, x, map, 2);
			}
		warm_flag = warm_flag == 2 ? 1 : 0;
		cold_flag = cold_flag == 2 ? 1 : 0;
	}
}

void	warm_map(t_map *map, int y, int x)
{
	warm_map_init(map);
	while (++y < map->height && (x = -1))
		while (++x < map->width)
		{
			if (map->field[y][x] == map->pl)
			{
				map->warm_map[y][x] = -1;
				map->cold_map[y][x] = -0;
			}
			if (map->field[y][x] == map->pl2)
			{
				map->warm_map[y][x] = 0;
				map->cold_map[y][x] = -1;
			}
		}
	make_warm_map(map, -1, -1);
	y = 0;
	while (y < map->height)
	{
		x = -1;
		while (++x < map->width)
			map->cold_map[y][x] += map->warm_map[y][x];
		y++;
	}
}
