/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 08:55:45 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 22:58:42 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	j;
	size_t	i;
	size_t	length_s2;

	length_s2 = ft_strlen(s2);
	if (n < length_s2)
		return (NULL);
	if (s2 == NULL || s2[0] == '\0')
		return ((char*)s1);
	else
	{
		i = 0;
		while (s1[i] && i < n)
		{
			j = 0;
			while (s1[i + j] == s2[j] && i + j < n)
			{
				if (s2[j + 1] == '\0')
					return ((char*)s1 + i);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
