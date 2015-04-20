/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 13:51:10 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/21 11:58:01 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char *get_name(char *name, t_opts *options)
{
	char	*new_name;

	if (D && name[0] == '/')
		return (name);
	else if (D && !(new_name = ft_strrchr(name, '/')))
		return (name);
	else if (!D && (new_name = ft_strrchr(name, '/')))
	{
		new_name++;
		return (new_name);
	}
	else
		return (name);
}

int			get_max_length(int max_l, char *name, t_opts *options)
{
	int		new_l;

	new_l = (int)ft_strlen(get_name(name, options));
	if (new_l > max_l)
		max_l = new_l;
	return (max_l);
}
