/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:05:12 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/06 10:34:16 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*newd;
	unsigned const char *news;

	newd = dst;
	news = src;
	if (newd >= news)
	{
		newd += len - 1;
		news += len - 1;
		i = len;
		while (i--)
			*newd-- = *news--;
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*newd++ = *news++;
			i++;
		}
	}
	return (dst);
}
