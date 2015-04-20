/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 00:10:06 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 21:08:12 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			*get_name(char *f_name, t_opts *options)
{
	char			*name;

	if (D && f_name[0] == '/')
		return (f_name);
	else if (D && !(name = ft_strrchr(f_name, '/')))
		return (f_name);
	else if (!D && (name = ft_strrchr(f_name, '/')))
	{
		name++;
		return (name);
	}
	else
		return (f_name);
}

static void			special_case(struct stat fstats)
{
	if ((((RIGHTS & S_ISUID && !(RIGHTS & S_IXOTH)) != 0) ||
		((RIGHTS & S_ISUID) != 0) || ((RIGHTS & S_IEXEC >> 0))) ||
		(((RIGHTS & S_ISGID && !(RIGHTS & S_IXGRP)) != 0) ||
		((RIGHTS & S_ISGID) != 0) || ((RIGHTS & S_IEXEC >> 3))) ||
		(((RIGHTS & S_ISVTX && !(RIGHTS & S_IXUSR)) != 0) ||
		((RIGHTS & S_ISVTX) != 0) || ((RIGHTS & S_IEXEC >> 6))))
		ft_putendl("*");
	else
		ft_putendl("");
}

static void			print_options_pf(const char *f_name, char *name,
		t_opts *options)
{
	struct stat		fstats;

	if (!P && !GF)
		ft_putendl(name);
	else if (P || GF)
	{
		lstat(f_name, &fstats);
		ft_putstr(name);
		if (GF && S_ISREG(RIGHTS))
			special_case(fstats);
		else if (GF && S_ISLNK(RIGHTS))
			ft_putendl("@");
		else if ((P || GF) && S_ISDIR(RIGHTS))
			ft_putendl("/");
		else if (GF && S_ISFIFO(RIGHTS))
			ft_putendl("|");
		else if (GF && S_ISSOCK(RIGHTS))
			ft_putendl("=");
		else
			ft_putendl("");
	}
}

static void			print_line(const t_tree *lfiles, t_opts *options,
		t_max *max_c)
{
	int			test;
	char		*name;
	char		*link;

	name = get_name(F_NAME, options);
	if ((test = option_l(F_NAME, options, max_c)) == 1)
	{
		if ((link = get_path_link(F_NAME)) && L)
		{
			ft_putstr(name);
			if (GF)
				ft_putchar('@');
			ft_putstr(" -> ");
			ft_putendl(link);
		}
		else
			print_options_pf(F_NAME, name, options);
	}
	else
	{
		if (test == 0 && errno == EACCES)
			get_error(2, 0, name);
		else if (test == 2)
			print_options_pf(F_NAME, name, options);
	}
}

void				print_nor(const t_tree *lfiles, t_opts *options,
		t_max *max_c, int check_d)
{
	if (lfiles)
	{
		ft_go_first_elem((t_tree**)&lfiles);
		if ((L || G == 1 || O == 1) && MAXT >= 0 && !check_d)
		{
			ft_putstr("total ");
			ft_putnbr(MAXT);
			ft_putendl("");
		}
		while (lfiles)
		{
			print_line(lfiles, options, max_c);
			lfiles = lfiles->right;
		}
		ft_putchar('\0');
		ft_destroy_tree((t_tree**)&lfiles);
	}
}
