/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 18:41:43 by sde-toda          #+#    #+#             */
/*   Updated: 2015/04/01 19:19:24 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_circ			*create_new_elem(char *data)
{
	t_circ		*new;

	new = NULL;
	if (data)
	{
		new = (t_circ*)ft_xmalloc(sizeof(t_circ));
		new->data = ft_strdup(data);
		new->end = 0;
		new->begin = 0;
		new->left = NULL;
		new->right = NULL;
		new->select = 0;
		new->position = 0;
	}
	return (new);
}
