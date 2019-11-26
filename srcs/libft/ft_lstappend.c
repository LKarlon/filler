/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:24:52 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/04/27 19:17:08 by lkarlon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list *alst, t_list *new)
{
	t_list	*cur;

	if (alst && new)
	{
		cur = alst;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
		new->next = NULL;
	}
}
