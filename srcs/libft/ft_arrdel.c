/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:56:53 by chermist          #+#    #+#             */
/*   Updated: 2019/01/19 23:39:52 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_arrdel(void **res)
{
	void	**tmp;

	tmp = res;
	while (res && *res)
		free(*res++);
	free(tmp);
	tmp = NULL;
	return (tmp);
}
