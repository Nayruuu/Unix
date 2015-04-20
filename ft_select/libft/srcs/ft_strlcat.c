/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:02:08 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 22:24:10 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (size <= i)
		return (size + j);
	if (j < size - i)
	{
		ft_memcpy(dst + i, src, j);
		dst += i + j;
	}
	else
	{
		ft_memcpy(dst + i, src, size - i - 1);
		dst += size - 1;
	}
	*dst = '\0';
	return (i + j);
}
