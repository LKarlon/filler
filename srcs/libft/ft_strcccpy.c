/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcccpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 22:04:54 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/08/11 22:09:24 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcccpy(char *src, char n)
{
	int		i;
	int		count;
	char	*dst;

	count = 0;
	i = -1;
	while (src[++i] && src[i] != n)
		count++;
	dst = (char*)malloc(sizeof(char) * (count + 1));
	ft_memcpy(dst, src, count);
	dst[count] = '\0';
	return (dst);
}