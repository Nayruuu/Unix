/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:35:52 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/09 07:54:27 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t					i;
	unsigned const char		*news1;
	unsigned const char		*news2;

	i = 0;
	news1 = (unsigned const char *)s1;
	news2 = (unsigned const char *)s2;
	while (i < n)
	{
		if (news1[i] != news2[i])
			return (news1[i] - news2[i]);
		if (news1[i] == '\0' || news2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
