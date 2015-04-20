/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_new_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 18:45:15 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/27 16:00:04 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			insert_new_elem(t_circ **list, t_circ *new_elem)
{
	t_circ		*temp;

	if (list && !*list)
	{
		new_elem->end = 1;
		new_elem->begin = 1;
		new_elem->position = 1;
		*list = new_elem;
	}
	else if (list && *list && new_elem)
	{
		temp = *list;
		while (temp->end == 0)
			temp = temp->right;
		temp->end = 0;
		new_elem->end = 1;
		temp->right = new_elem;
		new_elem->left = temp;
		new_elem->right = *list;
		(*list)->left = new_elem;
	}
}
