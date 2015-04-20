/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:08:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 23:08:30 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	if (new)
	{
		if (alst)
		{
			if ((*alst))
			{
				new->next = *alst;
				*alst = new;
			}
			else
				*alst = new;
		}
	}
}
