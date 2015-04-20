/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:45:39 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 13:16:27 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void			ft_putchar(char c)
{
	static int	i = 0;
	static char	stock[4000000];

	if (c != '\0')
	{
		stock[i] = c;
		i++;
	}
	else
	{
		stock[i] = '\0';
		if ((write(1, stock, i) == -1))
			write(2, "Writting Error", 14);
		i = 0;
	}
}
