/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 19:43:10 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/29 15:09:32 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				get_max_m(int max_m, struct stat fstats)
{
	int			new_m;

	new_m = (int)get_nbr_length(fstats.st_rdev >> 24);
	if (new_m > max_m)
		max_m = new_m;
	return (max_m);
}
