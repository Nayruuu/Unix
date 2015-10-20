/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 19:31:25 by sde-toda          #+#    #+#             */
/*   Updated: 2015/07/20 17:29:18 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static int			is_binary(struct stat fstats)
{
	if (UID_X || GRD_X || USR_X)
		return (1);
	else
		return (0);
}

static void			getbinaries(t_tree **list, char **path, char *line)
{
	int				i;
	DIR				*rep;
	struct dirent	*content;
	struct stat		fstats;

	i = 0;
	if (path)
	{
		while (path[i])
		{
			if (!stat(path[i], &fstats) && (rep = opendir(path[i])))
			{
				while (rep && (content = readdir(rep)))
				{
					if (!ft_strncmp(content->d_name, line, ft_strlen(line)) &&
						!ft_strchr(content->d_name, ' ') && is_binary(fstats))
						ft_sort_by_ascii(list, ft_new_elem(content->d_name));
				}
				closedir(rep);
			}
			i++;
		}
	}
}

void				get_all(t_tree **list, char **path, char *line)
{
	*list = ft_init_tree();
	if (ft_strchr(line, '/'))
		get_directories(list, line);
	else
		getbinaries(list, path, line);
	ft_go_first_elem(list);
}
