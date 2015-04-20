/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_by_size_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 21:59:35 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/16 17:41:21 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lui	get_size1(char *name)
{
	t_lui		tm;
	struct stat	fstats;

	if (lstat(name, &fstats) < 0)
		return (0);
	tm = fstats.st_size;
	return (tm);
}

static void		ft_sort_by_asc(t_tree **atree, t_tree *elem, t_lui size2)
{
	if (ft_strcmp((*atree)->data, elem->data) >= 0)
	{
		while ((*atree)->right && ft_strcmp((*atree)->data, elem->data) >= 0)
		{
			*atree = (*atree)->right;
			if (get_size1((*atree)->data) != size2)
			{
				*atree = (*atree)->left;
				break ;
			}
		}
	}
	else
	{
		while ((*atree)->left && ft_strcmp((*atree)->data, elem->data) < 0)
		{
			*atree = (*atree)->left;
			if (get_size1((*atree)->data) != size2)
			{
				*atree = (*atree)->right;
				break ;
			}
		}
	}
}

static void		ft_sort(t_tree **atree, t_tree *elem, t_lui size2)
{
	t_lui		size1;

	size1 = get_size1((*atree)->data);
	if (size1 > size2)
	{
		ft_insert_elem_l(atree, elem);
	}
	else if (size1 == size2)
	{
		ft_sort_by_asc(atree, elem, size2);
		if (ft_strcmp((*atree)->data, elem->data) < 0)
			ft_insert_elem_l(atree, elem);
		else
			ft_insert_elem_r(atree, elem);
	}
	else if (size1 < size2)
		ft_insert_elem_r(atree, elem);
}

void			ft_sort_by_size_r(t_tree **atree, t_tree *elem)
{
	t_lui		size2;

	size2 = get_size1(elem->data);
	if (!(*atree) && elem->data[0])
		*atree = elem;
	else if (*atree && elem->data[0])
	{
		if (get_size1((*atree)->data) < size2)
		{
			while ((*atree)->right && get_size1((*atree)->data) < size2)
				*atree = (*atree)->right;
		}
		else if (get_size1((*atree)->data) > size2)
		{
			while ((*atree)->left && get_size1((*atree)->data) > size2)
				(*atree) = (*atree)->left;
		}
		ft_sort(atree, elem, size2);
	}
}
