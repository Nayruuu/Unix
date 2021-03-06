/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_elem_l.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 02:59:28 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/12 19:54:27 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_insert_elem_l(t_tree **atree, t_tree *elem)
{
	t_tree		*current;

	if (atree)
	{
		if (!(*atree))
			*atree = elem;
		else
		{
			current = *atree;
			if (current->left == NULL)
			{
				current->left = elem;
				elem->left = NULL;
				elem->right = current;
			}
			else
			{
				elem->left = current->left;
				current->left->right = elem;
				current->left = elem;
				elem->right = current;
			}
			*atree = elem;
		}
	}
}
