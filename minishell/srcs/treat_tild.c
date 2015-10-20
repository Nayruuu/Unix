/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_tild.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 12:40:53 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 22:06:01 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void			treat_tild(char **command, char *shell_home)
{
	int			i;
	char		*temp;

	i = 0;
	while (command[i])
	{
		if ((temp = ft_strchr(command[i], '~')) && command[i][0] == '~')
		{
			temp = ft_strdup(temp + 1);
			ft_strdel(&command[i]);
			command[i] = ft_strjoin(shell_home, temp);
			ft_strdel(&temp);
		}
		i++;
	}
}
