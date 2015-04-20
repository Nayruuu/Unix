/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uid_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 15:27:07 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 19:44:50 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_spaces(int length)
{
	while (length--)
		ft_putchar(' ');
}

void				get_grd_name(t_opts *options, struct stat fstats,
		int max_g)
{
	struct group	*grd_name;

	if (!O)
	{
		grd_name = getgrgid(fstats.st_gid);
		if (grd_name)
		{
			ft_putstr(grd_name->gr_name);
			ft_putstr("  ");
			print_spaces(max_g - ft_strlen(grd_name->gr_name));
		}
		else
		{
			ft_putnbr(fstats.st_gid);
			ft_putstr("  ");
			print_spaces(max_g - get_nbr_length(fstats.st_gid));
		}
	}
	else if (O == 1 && G == 1)
		ft_putstr("  ");
}
