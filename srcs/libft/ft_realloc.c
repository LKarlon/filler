/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 00:04:16 by chermist          #+#    #+#             */
/*   Updated: 2019/04/03 21:25:12 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t prevsz, size_t newsz)
{
	void	*new;

	if (!ptr)
		return (NULL);
	if (!(new = ft_memalloc(newsz)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, (prevsz < newsz) ? prevsz : newsz);
	free(ptr);
	ptr = NULL;
	return (new);
}
