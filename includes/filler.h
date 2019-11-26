/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:20:23 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/09/04 18:01:26 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define POW(x) (((x) < 0) ? ((x) * -1) : (x))
# include "../srcs/libft/libft.h"

typedef struct	s_map
{
	int			width;
	int			height;
	int			w_p;
	int			h_p;
	char		**field;
	int			**warm_map;
	int			**cold_map;
	char		**piece;
	char		pl;
	char		pl2;
	int			ret_x;
	int			ret_y;
	int			warm;
}				t_map;

void			warm_map(t_map *map, int y, int x);
void			warmer(int y, int x, t_map *map);
int				draw_net(t_map *map);
void			warm_map_init(t_map *map);
void			print_result(t_map *map);
void			del_piece(t_map *map);
void			count_piece_size(char *str, t_map *map);
void			set_values(t_map *map, int x, int y, int warm);

#endif
