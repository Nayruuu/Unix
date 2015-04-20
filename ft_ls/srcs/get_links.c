/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 18:37:50 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 11:54:54 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_spaces(int length)
{
	while (length--)
		ft_putchar(' ');
}

void				get_links(struct stat fstats, int max_l)
{
	int				nbr;

	nbr = fstats.st_nlink;
	print_spaces(max_l - get_nbr_length(nbr));
	ft_putnbr(nbr);
	ft_putchar(' ');
}
