/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:27:07 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 23:08:59 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst && del && *alst)
	{
		temp = (*alst)->next;
		if (temp == NULL)
			ft_lstdelone(alst, del);
		else
		{
			while (temp)
			{
				temp = (*alst)->next;
				ft_lstdelone(alst, del);
				*alst = temp;
			}
		}
	}
}
