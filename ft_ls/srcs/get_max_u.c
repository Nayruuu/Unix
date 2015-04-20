/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 23:53:58 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/29 15:10:40 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					get_max_u(int max_u, struct stat fstats)
{
	int				new_u;
	struct passwd	*uid_name;

	uid_name = getpwuid(fstats.st_uid);
	if (uid_name)
		new_u = (int)ft_strlen(uid_name->pw_name);
	else
		new_u = (int)get_nbr_length(fstats.st_uid);
	if (new_u > max_u)
		max_u = new_u;
	return (max_u);
}
