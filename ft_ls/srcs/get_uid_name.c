/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uid_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 15:27:07 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 19:44:51 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			print_spaces(int length)
{
	while (length--)
		ft_putchar(' ');
}

void				get_uid_name(t_opts *options, struct stat fstats, int max_u)
{
	struct passwd	*uid_name;

	if (!G)
	{
		uid_name = getpwuid(fstats.st_uid);
		if (uid_name)
		{
			ft_putstr(uid_name->pw_name);
			ft_putstr("  ");
			print_spaces(max_u - ft_strlen(uid_name->pw_name));
		}
		else
		{
			ft_putnbr(fstats.st_uid);
			ft_putstr("  ");
			print_spaces(max_u - get_nbr_length(fstats.st_uid));
		}
	}
}
