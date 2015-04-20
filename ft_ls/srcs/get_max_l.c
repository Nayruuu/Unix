/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 23:49:42 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/29 15:09:21 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				get_max_l(int max_l, struct stat fstats)
{
	int			new_l;

	new_l = (int)get_nbr_length(fstats.st_nlink);
	if (new_l > max_l)
		max_l = new_l;
	return (max_l);
}
