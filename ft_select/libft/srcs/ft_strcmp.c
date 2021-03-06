/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:35:52 by sde-toda          #+#    #+#             */
/*   Updated: 2015/04/01 12:15:51 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_strcmp(const char *s1, const char *s2)
{
	if (s1 && s2)
	{
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s1 != *s2)
			return ((unsigned char)*s1 - *s2);
		else
			return (0);
	}
	else
		return (0);
}
