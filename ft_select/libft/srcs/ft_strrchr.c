/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:57:45 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/10 10:58:36 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*cur;

	i = 0;
	cur = NULL;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (i < ft_strlen(s))
	{
		if (s[i] == c)
			cur = (char*)&s[i];
		i++;
	}
	return (cur);
}
