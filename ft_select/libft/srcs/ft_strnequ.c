/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:34:18 by sde-toda          #+#    #+#             */
/*   Updated: 2014/11/10 10:58:11 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		nequ;

	if (s1 && s2)
	{
		nequ = (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
		return (nequ);
	}
	return (0);
}
