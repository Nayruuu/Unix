/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:45:47 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/10 10:56:40 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char		*news1;
	unsigned const char		*news2;

	news1 = s1;
	news2 = s2;
	while (n--)
	{
		if (*news1 != *news2)
			return ((*news1 - *news2));
		news1++;
		news2++;
	}
	return (0);
}
