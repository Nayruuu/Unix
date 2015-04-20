/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:42:09 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/10 12:03:59 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_string(void)
{
	char	*new;

	new = ft_strnew(0);
	if (new)
		return (new);
	else
		return (NULL);
}

char		*ft_strtrim(char const *s)
{
	size_t	k;
	size_t	i;
	char	*new;

	if (s)
	{
		i = 0;
		k = ft_strlen(s) - 1;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
		while ((s[k] == ' ' || s[k] == '\n' || s[k] == '\t') && k > 0)
			k--;
		if (i == ft_strlen(s))
			return (empty_string());
		new = ft_strnew(k - i + 1);
		if (new)
		{
			new = ft_strsub(s, i, k - i + 1);
			return (new);
		}
	}
	return (NULL);
}
