/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 00:06:39 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 19:43:41 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			get_max_chars(char *name, t_max *max_c, t_opts *options)
{
	struct stat	fstats;

	if (L || G == 1 || O == 1)
	{
		if (lstat(name, &fstats) >= 0)
		{
			MAXL = get_max_l(MAXL, fstats);
			MAXU = get_max_u(MAXU, fstats);
			MAXG = get_max_g(MAXG, fstats);
			if (!S_ISCHR(RIGHTS) && !S_ISBLK(RIGHTS))
				MAXS = get_max_s(MAXS, fstats);
			if (S_ISCHR(RIGHTS) || S_ISBLK(RIGHTS))
				MAXM = get_max_m(MAXM, fstats);
			MAXT = get_total(MAXT, fstats);
		}
		else
			MAXT = -1;
	}
}
