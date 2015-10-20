/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 19:34:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/13 19:08:19 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char				**get_path(char **char_env)
{
	int				i;
	int				found;

	i = -1;
	found = 0;
	while (!found && char_env[++i])
	{
		if (ft_strstr(char_env[i], "PATH"))
			found = 1;
	}
	if (found && char_env)
		return (ft_strsplit(char_env[i] + 5, ':'));
	else
		return (ft_strsplit(PATH, ':'));
}
