/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_end_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:44:15 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/14 15:48:28 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_insert_end_tree(t_tree **atree, t_tree *new)
{
	t_tree	*temp;

	if (*atree)
	{
		temp = *atree;
		while (temp->right)
			temp = temp->right;
		ft_insert_elem_r(&temp, new);
	}
	else
	{
		*atree = new;
	}
}
