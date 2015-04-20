/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:22:40 by sde-toda          #+#    #+#             */
/*   Updated: 2015/04/01 19:57:22 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			size_list(t_circ *list)
{
	int		count;

	count = 0;
	while (list && !list->end)
	{
		count++;
		list = list->right;
	}
	count++;
	return (count);
}
