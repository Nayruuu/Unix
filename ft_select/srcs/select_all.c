/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 17:47:16 by sde-toda          #+#    #+#             */
/*   Updated: 2015/04/01 18:09:41 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			select_all(t_circ **list, int choice, int select)
{
	t_circ		*temp;

	temp = *list;
	if (choice == 1)
	{
		while (!temp->end)
		{
			temp->select = select;
			temp = temp->right;
		}
		temp->select = select;
	}
	else
	{
		while (!temp->end)
		{
			temp->select = temp->select ? 0 : 1;
			temp = temp->right;
		}
		temp->select = temp->select ? 0 : 1;
	}
}
