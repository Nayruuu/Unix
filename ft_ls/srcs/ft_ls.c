/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 20:19:33 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 13:07:20 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		is_file(char *name)
{
	struct stat fstats;

	if (lstat(name, &fstats) < 0)
		return (1);
	else
		return (0);
}

static int		init(char **argv, int argc, t_opts *options)
{
	int			i;
	static int	check = 0;

	i = 1;
	if (argc > 1)
	{
		while (i < argc && argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
		{
			if (ft_strstr(argv[i], "--") && !check)
				check++;
			else if (!ft_strcmp(argv[i], "--") && check)
				break ;
			if (!ft_strcmp(argv[i - 1], "--") && !is_file(argv[i]))
				break ;
			check_options(argv[i], options);
			i++;
		}
		if (i < argc)
		{
			if (!F)
				ft_strsort(&argv[i], argc - i);
			check_files(&argv[i], argc - i, options);
		}
	}
	return (i);
}

static void		print_point_d(t_tree *lfiles, t_opts *options, t_max *max_c)
{
	option_trs(&lfiles, NULL, ".", options);
	get_max_chars(".", max_c, options);
	print_nor(lfiles, options, max_c, 1);
}

static void		option_f(t_tree **lfiles, char *argv, t_opts *options)
{
	if (!F)
		option_trs(lfiles, NULL, argv, options);
	else if (F && argv[0] != '\0')
		ft_insert_elem_r(lfiles, ft_new_elem(argv));
}

int				main(int argc, char **argv)
{
	int			i;
	t_tree		*lfiles;
	t_max		*max_c;
	t_opts		*options;

	max_c = init_max_chars();
	lfiles = ft_init_tree();
	options = (t_opts*)ft_memalloc(sizeof(t_opts));
	i = init(argv, argc, options);
	if (!D)
		not_option_d(i, argc, argv, options);
	else if (D && i < argc)
	{
		while (i < argc)
		{
			option_f(&lfiles, argv[i], options);
			get_max_chars(argv[i], max_c, options);
			i++;
		}
		ft_go_first_elem(&lfiles);
		print_nor(lfiles, options, max_c, 1);
	}
	else if (D && i == argc)
		print_point_d(lfiles, options, max_c);
	return (0);
}
