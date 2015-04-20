/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_elem_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 02:59:28 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/08 20:35:22 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_insert_elem_r(t_tree **atree, t_tree *elem)
{
	t_tree		*current;

	if (atree)
	{
		if (!(*atree))
			*atree = elem;
		else
		{
			current = *atree;
			if (current->right == NULL)
			{
				current->right = elem;
				elem->right = NULL;
				elem->left = current;
			}
			else
			{
				elem->right = current->right;
				current->right->left = elem;
				current->right = elem;
				elem->left = current;
			}
			*atree = elem;
		}
	}
}
