/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 08:55:45 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/10 10:58:56 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2 == NULL || s2[0] == '\0')
		return ((char*)s1);
	else
	{
		while (i < ft_strlen(s1))
		{
			if (s1[i] == s2[j])
				j++;
			else
				j = 0;
			if (j == (ft_strlen(s2)) || s2[j] == '\0')
				return ((char*)&s1[i - ft_strlen(s2) + 1]);
			i++;
		}
	}
	return (NULL);
}
