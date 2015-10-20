/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:35:19 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/07 16:55:15 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int				neg;
	long int		value;

	neg = 0;
	value = 0;
	if (str == NULL)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = (value * 10) + (*str - 48);
		str++;
	}
	if (value > 0 && neg == 1)
		value = -value;
	return (value);
}
