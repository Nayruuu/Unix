/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 05:30:13 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 19:51:39 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del_content(t_tree **atree)
{
	ft_strdel(&((*atree)->data));
	free(*atree);
	*atree = NULL;
}

static void		first_case(t_tree **atree)
{
	*atree = (*atree)->right;
	del_content(&((*atree)->left));
	(*atree)->left = NULL;
}

static void		second_case(t_tree **atree)
{
	t_tree		*temp;

	temp = (*atree)->left;
	(*atree)->left->right = (*atree)->right;
	(*atree)->right->left = (*atree)->left;
	del_content(&(*atree));
	*atree = temp;
}

static void		last_case(t_tree **atree)
{
	t_tree		*temp;

	temp = (*atree)->left;
	del_content(&(*atree));
	*atree = temp;
	(*atree)->right = NULL;
}

void			ft_destroy_elem(t_tree **atree)
{
	t_tree		*current;

	if (atree && *atree)
	{
		current = *atree;
		if (current->left == NULL && current->right)
			first_case(&current);
		else if (current->left && current->right)
			second_case(&current);
		else if (current->left && current->right == NULL)
			last_case(&current);
		else if (!current->left && !current->right)
		{
			del_content(atree);
			*atree = NULL;
			return ;
		}
		*atree = current;
	}
}
