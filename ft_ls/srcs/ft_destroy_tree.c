/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 05:53:28 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/11 12:10:10 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_destroy_tree(t_tree **tree)
{
	t_tree		*temp;

	if (tree && *tree)
	{
		while ((*tree)->left)
			*tree = (*tree)->left;
		temp = (*tree)->right;
		if (temp == NULL)
			ft_destroy_elem(tree);
		else
		{
			while (temp)
			{
				temp = (*tree)->right;
				ft_destroy_elem(tree);
				*tree = temp;
			}
		}
	}
}
