/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 18:31:41 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 11:55:32 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_spaces(int length)
{
	while (length--)
		ft_putchar(' ');
}

void				get_size(struct stat fstats, int max_s, int spaces)
{
	int				nbr;

	nbr = fstats.st_size;
	if (spaces)
	{
		if (spaces > max_s)
			spaces += 5;
		else
			spaces += max_s - 2;
	}
	print_spaces(max_s + spaces - get_nbr_length(nbr));
	ft_putnbr(nbr);
	ft_putchar(' ');
}
