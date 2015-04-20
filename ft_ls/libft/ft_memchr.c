/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:14:01 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 12:58:50 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*news;

	i = 0;
	news = s;
	if (!s)
		return (NULL);
	while (i < n)
	{
		if ((unsigned char)news[i] == (unsigned char)c)
			return ((void*)&news[i]);
		i++;
	}
	return (NULL);
}
