/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_by_time_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 21:59:35 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/20 17:28:31 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lui	get_time(char *name, t_opts *options)
{
	t_lui		tm;
	struct stat	fstats;

	if (lstat(name, &fstats) < 0)
		return (0);
	tm = fstats.st_mtime;
	tm = (U == 1) ? (t_lui)fstats.st_atime : tm;
	tm = (C == 1) ? (t_lui)fstats.st_ctime : tm;
	tm = (GU == 1) ? (t_lui)fstats.st_birthtime : tm;
	return (tm);
}

static void		ft_sort_by_asc(t_tree **atree, t_tree *elem, t_lui time2,
		t_opts *options)
{
	if (ft_strcmp((*atree)->data, elem->data) >= 0)
	{
		while ((*atree)->right && ft_strcmp((*atree)->data, elem->data) >= 0)
		{
			*atree = (*atree)->right;
			if (get_time((*atree)->data, options) != time2)
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
			if (get_time((*atree)->data, options) != time2)
			{
				*atree = (*atree)->right;
				break ;
			}
		}
	}
}

static void		ft_sort(t_tree **atree, t_tree *elem, t_lui time2,
		t_opts *options)
{
	t_lui		time1;

	time1 = get_time((*atree)->data, options);
	if (time1 > time2)
	{
		ft_insert_elem_l(atree, elem);
	}
	else if (time1 == time2)
	{
		ft_sort_by_asc(atree, elem, time2, options);
		if (ft_strcmp((*atree)->data, elem->data) < 0)
			ft_insert_elem_l(atree, elem);
		else
			ft_insert_elem_r(atree, elem);
	}
	else if (time1 < time2)
		ft_insert_elem_r(atree, elem);
}

void			ft_sort_by_time_r(t_tree **atree, t_tree *elem, t_opts *options)
{
	t_lui		time2;

	time2 = get_time(elem->data, options);
	if (!(*atree) && elem->data[0])
		*atree = elem;
	else if (*atree && elem->data[0])
	{
		if (get_time((*atree)->data, options) < time2)
		{
			while ((*atree)->right && get_time((*atree)->data, options) < time2)
				*atree = (*atree)->right;
		}
		else if (get_time((*atree)->data, options) > time2)
		{
			while ((*atree)->left && get_time((*atree)->data, options) > time2)
				(*atree) = (*atree)->left;
		}
		ft_sort(atree, elem, time2, options);
	}
}
