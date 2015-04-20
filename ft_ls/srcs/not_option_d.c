/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_option_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 13:33:10 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/21 16:44:32 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_ls(t_tree *lfiles, t_tree *ldirec, t_opts *options,
		t_max *max_c)
{
	print_fargv(lfiles, ldirec, options, max_c);
	if (lfiles)
		print_dargv(ldirec, 1, options);
	else
		print_dargv(ldirec, CHECK, options);
	ft_destroy_tree(&lfiles);
	ft_destroy_tree(&ldirec);
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

static void		option_f(t_tree **lfiles, t_tree **ldirec, char *argv,
		t_opts *options)
{
	if (!F)
		option_trs(lfiles, ldirec, argv, options);
	else
	{
		if (!is_type(ft_strjoin(get_path(argv), get_path_link(argv)), options)
				&& argv[0] && !L && !G)
			ft_insert_elem_r(ldirec, ft_new_elem(argv));
		else if (is_type(argv, options) && argv[0])
			ft_insert_elem_r(lfiles, ft_new_elem(argv));
		else if (!is_type(argv, options) && argv[0])
			ft_insert_elem_r(ldirec, ft_new_elem(argv));
	}
}

void			not_option_d(int i, int argc, char **argv, t_opts *options)
{
	t_max		*max_c;
	t_tree		*lfiles;
	t_tree		*ldirec;

	max_c = init_max_chars();
	if (i < argc)
	{
		lfiles = ft_init_tree();
		ldirec = ft_init_tree();
		while (i < argc)
		{
			option_f(&lfiles, &ldirec, argv[i], options);
			if (is_type(argv[i], options) && argv[i][0] &&
					(L || G || !ONE))
				get_max_chars(argv[i], max_c, options);
			i++;
		}
		print_ls(lfiles, ldirec, options, max_c);
	}
	else
		read_rec(".", options);
}
