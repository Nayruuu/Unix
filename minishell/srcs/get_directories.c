/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 19:31:25 by sde-toda          #+#    #+#             */
/*   Updated: 2015/07/04 11:56:06 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void			check_directory(t_tree **list, char *path, char *line)
{
	DIR				*rep;
	struct dirent	*content;

	if ((rep = opendir(path)))
	{
		while (rep && (content = readdir(rep)))
		{
			if (line[0] == '.' && ft_strcmp(content->d_name, ".") &&
					ft_strcmp(content->d_name, ".."))
			{
				if (!ft_strchr(content->d_name, ' ') &&
					!ft_strncmp(content->d_name, line, ft_strlen(line)))
					ft_sort_by_ascii(list, ft_new_elem(content->d_name));
			}
			else if (line[0] != '.' && ft_strcmp(content->d_name, ".") &&
					ft_strcmp(content->d_name, ".."))
			{
				if (!ft_strchr(content->d_name, ' ') &&
					!ft_strncmp(content->d_name, line, ft_strlen(line)))
					ft_sort_by_ascii(list, ft_new_elem(content->d_name));
			}
		}
		closedir(rep);
	}
}

void				get_directories(t_tree **list, char *line)
{
	int				i;
	char			*path;
	char			*temp_line;

	*list = ft_init_tree();
	if (ft_strchr(line, '/'))
	{
		i = ft_strlen(line);
		while (line[i] != '/')
			i--;
		path = ft_strsub(line, 0, i + 1);
		temp_line = ft_strsub(line, i + 1, ft_strlen(line));
		check_directory(list, path, temp_line);
		free(temp_line);
		free(path);
	}
	else
		check_directory(list, ".", line);
	ft_go_first_elem(list);
}
