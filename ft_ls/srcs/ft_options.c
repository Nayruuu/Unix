/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 22:41:06 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/04 12:12:01 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		option_r(t_tree **atree, char *cont, t_opts *options)
{
	if (REV)
	{
		if (T && !GS)
			ft_sort_by_time_r(atree, ft_new_elem(cont), options);
		else if (GS)
			ft_sort_by_size_r(atree, ft_new_elem(cont));
		else
			ft_sort_by_ascii_r(atree, ft_new_elem(cont));
	}
	else
	{
		if (T && !GS)
			ft_sort_by_time(atree, ft_new_elem(cont), options);
		else if (GS)
			ft_sort_by_size(atree, ft_new_elem(cont));
		else
			ft_sort_by_ascii(atree, ft_new_elem(cont));
	}
}

static char		*get_path(char *cont)
{
	int			i;
	char		*name;

	if ((name = ft_strrchr(cont, '/')))
	{
		name++;
		i = (int)ft_strlen(name);
		name = ft_strsub(cont, 0, ft_strlen(cont) - i);
	}
	else
		name = ft_strdup("/");
	return (name);
}

void			option_trs(t_tree **lfil, t_tree **ldir, char *cont,
		t_opts *options)
{
	if (ldir)
	{
		if (cont[0] &&
			!is_type(ft_strjoin(get_path(cont), get_path_link(cont)), options)
				&& !L && !G)
			option_r(ldir, cont, options);
		else if (is_type(cont, options))
			option_r(lfil, cont, options);
		else
			option_r(ldir, cont, options);
	}
	else
	{
		option_r(lfil, cont, options);
	}
}

int				option_l(char *name, t_opts *options, t_max *max_c)
{
	struct stat	fstats;

	if (L || G == 1 || O == 1)
	{
		if (lstat(name, &fstats) < 0)
			return (0);
		else
		{
			get_rights(fstats);
			get_attr(name);
			get_links(fstats, MAXL);
			get_uid_name(options, fstats, MAXU);
			get_grd_name(options, fstats, MAXG);
			if (!S_ISCHR(RIGHTS) && !S_ISBLK(RIGHTS))
				get_size(fstats, MAXS, MAXM);
			else if (S_ISCHR(RIGHTS) || S_ISBLK(RIGHTS))
			{
				ft_putchar(' ');
				get_major_minor(fstats, MAXM);
			}
			get_date(fstats, options);
		}
		return (1);
	}
	return (2);
}
