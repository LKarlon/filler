/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqroot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:45:36 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/04/27 19:12:31 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqroot(int x)
{
	int y;

	y = 0;
	while (y * y < x)
		y++;
	return ((y * y) > x ? y - 1 : y);
}
