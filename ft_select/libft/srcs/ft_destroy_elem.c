/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 05:30:13 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/04 14:34:12 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del_content(t_tree **atree)
{
	ft_strdel(&((*atree)->data));
	free(*atree);
	*atree = NULL;
}

static void		first_case(t_tree **atree, t_tree *current)
{
	current->right->left = NULL;
	*atree = current->right;
	del_content(&current);
}

static void		second_case(t_tree *current)
{
	current->left->right = current->right;
	current->right->left = current->left;
	del_content(&current);
}

static void		last_case(t_tree **atree, t_tree *current)
{
	current->left->right = NULL;
	*atree = current->left;
	del_content(&current);
}

void			ft_destroy_elem(t_tree **atree)
{
	t_tree		*current;

	if (atree && *atree)
	{
		current = *atree;
		if (current->left == NULL && current->right)
		{
			first_case(atree, current);
		}
		else if (current->left && current->right)
		{
			second_case(current);
		}
		else if (current->left && current->right == NULL)
		{
			last_case(atree, current);
		}
		else if (!current->left && !current->right)
			del_content(atree);
	}
}
