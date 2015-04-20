/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_major_minor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 19:37:21 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 11:56:59 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_spaces(int length)
{
	while (length--)
		ft_putchar(' ');
}

void			get_major_minor(struct stat fstats, int max_m)
{
	int			nbr;

	nbr = (fstats.st_rdev >> 24);
	print_spaces(max_m - get_nbr_length(nbr));
	ft_putnbr(nbr);
	ft_putstr(", ");
	nbr = (fstats.st_rdev & 255);
	print_spaces(3 - get_nbr_length(nbr));
	ft_putnbr(nbr);
	ft_putchar(' ');
}
