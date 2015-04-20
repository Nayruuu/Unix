/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:22:55 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 12:58:41 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*newd;
	const char	*news;

	newd = dst;
	news = src;
	if (!dst || !src)
		return (NULL);
	while (n--)
	{
		if (*news == c)
		{
			*newd++ = *news++;
			return (newd);
		}
		*newd++ = *news++;
	}
	return (NULL);
}
