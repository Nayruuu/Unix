/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_date.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 16:12:32 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 12:08:11 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				get_date(struct stat fstats, t_opts *options)
{
	time_t			now;
	time_t			f_time;

	f_time = fstats.st_mtime;
	f_time = (U == 1) ? fstats.st_atime : f_time;
	f_time = (C == 1) ? fstats.st_ctime : f_time;
	f_time = (GU == 1) ? fstats.st_birthtime : f_time;
	now = time (NULL);
	if (!GT)
	{
		if (f_time > now - 15642000 && f_time < now + 60)
			ft_putstr(ft_strsub(ctime(&f_time), 4, 12));
		else
		{
			ft_putstr(ft_strsub(ctime(&f_time), 4, 7));
			ft_putchar(' ');
			ft_putstr(ft_strsub(ctime(&f_time), 20, 4));
		}
	}
	else
		ft_putstr(ft_strsub(ctime(&f_time), 4, 20));
	ft_putchar(' ');
}
