/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:06:42 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/09 08:46:27 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new;

	i = 0;
	if (s && f)
	{
		new = (char*)malloc(ft_strlen(s) * sizeof(new));
		if (new)
		{
			while (s[i] != '\0')
			{
				new[i] = f(s[i]);
				i++;
			}
			new[i] = '\0';
			return (new);
		}
	}
	return (NULL);
}
