/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:30:49 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 23:25:24 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (s1 && s2)
	{
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (new)
		{
			ft_strcat(new, s1);
			ft_strcat(new, s2);
			return (new);
		}
	}
	return (NULL);
}
