/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_max_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 00:26:54 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 13:10:01 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_max		*init_max_chars(void)
{
	t_max	*max_c;

	max_c = (t_max*)ft_xmalloc(sizeof(t_max));
	if (!max_c)
	{
		write(1, "ft_ls: insufficient memory\n", 27);
		exit (1);
	}
	MAXL = 0;
	MAXU = 0;
	MAXG = 0;
	MAXS = 0;
	MAXT = 0;
	MAXM = 0;
	return (max_c);
}
