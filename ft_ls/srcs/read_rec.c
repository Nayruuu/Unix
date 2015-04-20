/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 15:10:56 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 13:10:39 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*get_test(char *name)
{
	char		*test;

	if (ft_strcmp(name, "."))
	{
		if ((test = ft_strrchr(name, '/')))
			test++;
		else
			test = name;
	}
	else
		test = name;
	return (test);
}

static void		read_rep(char *name, t_tree *ldir, t_opts *options, int check)
{
	char		*test;
	DIR			*rep_rec;

	if (ldir)
	{
		test = get_test(name);
		if (((!A && test[0] != '.') || A || GA || F) && check)
		{
			ft_putendl("");
			ft_putstr(name);
			ft_putendl(":");
		}
		ft_putchar('\0');
		if ((rep_rec = opendir(name)))
		{
			read_rec(name, options);
			closedir(rep_rec);
		}
		else
			get_error(2, 0, name);
	}
}

static int		check_dir(t_tree *lfiles)
{
	int			check;
	DIR			*rep;

	check = 0;
	while (lfiles)
	{
		if ((rep = opendir(F_NAME)))
		{
			check = 1;
			closedir(rep);
		}
		else
			break ;
		lfiles = lfiles->right;
	}
	if (!lfiles && check == 1)
		return (1);
	return (0);
}

static int		check_print(t_tree *lfiles, t_opts *options, t_max *max_c,
		char *name)
{
	char		*test;
	static int	count = 0;

	test = get_test(name);
	if ((!check_dir(lfiles) && !count) || !REC ||
		(REC && ((!A && test[0] != '.') || A || GA || F
		|| !ft_strcmp(name, "."))))
	{
		count++;
		print_nor(lfiles, options, max_c, 0);
		return (1);
	}
	return (0);
}

void			read_rec(char *name, t_opts *options)
{
	static int	check = 0;
	t_tree		*lfiles;
	t_tree		*ldirec;
	t_max		*max_c;

	max_c = init_max_chars();
	ldirec = ft_init_tree();
	if ((lfiles = read_dir(name, &ldirec, options, max_c)))
	{
		if (!check)
			check = check_print(lfiles, options, max_c, name);
		else
			check_print(lfiles, options, max_c, name);
	}
	if (REC && ldirec)
	{
		ft_go_first_elem(&ldirec);
		while (ldirec->right)
		{
			read_rep(D_NAME, ldirec, options, check);
			ldirec = ldirec->right;
		}
		read_rep(D_NAME, ldirec, options, check);
		ft_destroy_tree(&ldirec);
	}
}
