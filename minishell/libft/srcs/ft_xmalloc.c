/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 12:53:34 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/04 15:24:31 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_xmalloc(size_t size)
{
	void		*new;

	if (size == 0)
		size = 1;
	new = (void*)malloc(size);
	if (new == NULL)
		write(2, "Insufficient Memory", 19);
	return (new);
}
