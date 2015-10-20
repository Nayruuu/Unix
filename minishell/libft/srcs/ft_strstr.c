/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 08:55:45 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 22:49:08 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *s1, const char *s2)
{
	size_t			length_s2;

	length_s2 = ft_strlen(s2);
	if (s2 == NULL || s2[0] == '\0')
		return ((char*)s1);
	else
	{
		while (*s1)
		{
			if (ft_strncmp(s1, s2, length_s2) == 0)
				return ((char*)s1);
			s1++;
		}
	}
	return (NULL);
}
