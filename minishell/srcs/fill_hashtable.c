/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hashtable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 19:15:25 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/12 20:04:56 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void				fill_hashtable(t_shell *shell)
{
	int				i;
	DIR				*rep;
	struct dirent	*content;
	struct stat		fstats;

	i = -1;
	if (shell->path)
	{
		while (shell->path[++i])
		{
			if (!stat(shell->path[i], &fstats) &&
				(rep = opendir(shell->path[i])))
			{
				while (rep && (content = readdir(rep)))
					haching(content->d_name, shell->path[i], shell->tab);
				closedir(rep);
			}
		}
	}
}
