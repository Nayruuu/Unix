/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 23:59:12 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/29 15:09:26 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				get_max_s(int max_s, struct stat fstats)
{
	int			new_s;

	new_s = (int)get_nbr_length(fstats.st_size);
	if (new_s > max_s)
		max_s = new_s;
	return (max_s);
}
