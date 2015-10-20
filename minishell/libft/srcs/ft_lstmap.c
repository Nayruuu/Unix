/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 02:33:05 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/22 13:45:56 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*srch;
	t_list	*start;
	t_list	*new_lst;

	start = NULL;
	if (lst && f)
	{
		srch = lst;
		if ((new_lst = ft_lstnew(f(lst)->content, f(srch)->content_size)))
			start = new_lst;
		while (srch->next)
		{
			if (srch->next)
				new_lst->next = ft_lstnew(f(srch->next)->content,
						f(srch->next)->content_size);
			else
				new_lst->next = NULL;
			new_lst = new_lst->next;
			if (new_lst == NULL)
				return (NULL);
			srch = srch->next;
		}
		return (start);
	}
	return (NULL);
}
