/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_by_ascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 19:31:00 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/13 19:31:49 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void			ft_sort_by_ascii(t_tree **atree, t_tree *elem)
{
	if (!(*atree) && elem->data[0])
		*atree = elem;
	else if (*atree && elem->data[0])
	{
		if (ft_strcmp((*atree)->data, elem->data) < 0)
		{
			while ((*atree)->right &&
					ft_strcmp((*atree)->data, elem->data) < 0)
				*atree = (*atree)->right;
		}
		else
		{
			while ((*atree)->left &&
					ft_strcmp((*atree)->data, elem->data) >= 0)
				*atree = (*atree)->left;
		}
		if (ft_strcmp((*atree)->data, elem->data) < 0)
			ft_insert_elem_r(atree, elem);
		else
			ft_insert_elem_l(atree, elem);
	}
}
