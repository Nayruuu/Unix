/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 02:51:09 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/04 14:33:55 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree			*ft_new_elem(char *content)
{
	t_tree		*new_elem;

	if (!content)
		return (NULL);
	if (!(new_elem = (t_tree*)ft_xmalloc(sizeof(t_tree))))
		return (NULL);
	new_elem->data = ft_strdup(content);
	new_elem->left = NULL;
	new_elem->right = NULL;
	return (new_elem);
}
