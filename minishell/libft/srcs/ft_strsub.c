/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:48:23 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 23:43:26 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s || (s && !*s && len > 0))
		return (NULL);
	new = ft_strnew(len);
	if (new)
		new = ft_strncpy(new, &s[start], len);
	else
		return (NULL);
	return (new);
}
