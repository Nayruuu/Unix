/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:00:46 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 12:59:50 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	j;
	char	*new;

	j = ft_strlen(s1);
	if (s1)
		new = (char*)ft_xmalloc(sizeof(char) * (j + 1));
	else
		return (NULL);
	if (new)
	{
		ft_strcpy(new, s1);
		return (new);
	}
	else
		return (NULL);
}
