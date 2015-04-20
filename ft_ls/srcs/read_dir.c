/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 00:10:06 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/04 12:42:16 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			*get_path(char *dir, char *name_f)
{
	char			*path;

	if (ft_strcmp(dir, "/"))
	{
		path = ft_strjoin(dir, "/");
		path = ft_strjoin(path, name_f);
	}
	else
		path = ft_strjoin(dir, name_f);
	return (path);
}

static void			fill_dir(t_tree **ldirec, char *name, t_opts *options)
{
	char			*test;

	if (REC && (!is_type(name, options)))
	{
		test = ft_strrchr(name, '/');
		test++;
		if (ft_strcmp(test, ".") && ft_strcmp(test, ".."))
		{
			if (!F)
				option_trs(ldirec, NULL, name, options);
			else
				ft_insert_elem_r(ldirec, ft_new_elem(name));
		}
	}
}

static DIR			*get_rep(char *name)
{
	DIR				*rep;

	if ((rep = opendir(name)))
		return (rep);
	else
	{
		get_error(2, 0, name);
		return (NULL);
	}
}

static void			get_informations(t_tree **lfiles, char *path,
		t_opts *options, t_max *max_c)
{
	if (!F)
		option_trs(lfiles, NULL, path, options);
	else
		ft_insert_elem_r(lfiles, ft_new_elem(path));
	get_max_chars(path, max_c, options);
}

t_tree				*read_dir(char *name, t_tree **ldirec, t_opts *options,
		t_max *max_c)
{
	DIR				*rep;
	char			*path;
	t_tree			*lfiles;
	struct dirent	*content;

	lfiles = ft_init_tree();
	if ((rep = get_rep(name)))
	{
		while ((content = readdir(rep)))
		{
			path = get_path(name, NAME);
			if (GA && !A && ft_strcmp(NAME, ".") && ft_strcmp(NAME, ".."))
				get_informations(&lfiles, path, options, max_c);
			else if ((A || F) && NAME[0] == '.')
				get_informations(&lfiles, path, options, max_c);
			else if (NAME[0] != '.')
				get_informations(&lfiles, path, options, max_c);
			fill_dir(ldirec, path, options);
		}
		closedir(rep);
	}
	return (lfiles);
}
