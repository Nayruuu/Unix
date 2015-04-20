/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:02:08 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/12 15:02:41 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = ft_strlen(dst);
	k = ft_strlen(dst);
	if (size > k + 1)
	{
		while ((j < (size - k - 1)) && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		if (size > ft_strlen(src))
			dst[i] = '\0';
		dst[i + j - 1] = '\0';
	}
	if (size < k)
		return (size + ft_strlen(src));
	if (size >= k && size < k + ft_strlen(src))
		return (k + ft_strlen(src));
	else
		return (size);
}
