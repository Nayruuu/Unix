/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 23:57:08 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/29 15:09:48 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					get_max_g(int max_g, struct stat fstats)
{
	int				new_g;
	struct group	*grd_name;

	grd_name = getgrgid(fstats.st_gid);
	if (grd_name)
		new_g = (int)ft_strlen(grd_name->gr_name);
	else
		new_g = (int)get_nbr_length(fstats.st_gid);
	if (new_g > max_g)
		max_g = new_g;
	return (max_g);
}
