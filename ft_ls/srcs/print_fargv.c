/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fargv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 20:07:48 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 12:04:25 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_line(t_tree *lfiles, t_opts *options, t_max *max_c)
{
	int			test;
	char		*link;

	if ((test = option_l(F_NAME, options, max_c)) == 1)
	{
		if ((link = get_path_link(F_NAME)) && L)
		{
			ft_putstr(F_NAME);
			ft_putstr(" -> ");
			ft_putendl(link);
		}
		else
			ft_putendl(F_NAME);
	}
	else
	{
		if (test == 0 && errno == EACCES)
			get_error(2, 0, F_NAME);
		else if (test == 2)
			ft_putendl(F_NAME);
	}
}

void			print_fargv(t_tree *lfil, t_tree *ldir,
		t_opts *options, t_max *max_c)
{
	if (lfil)
	{
		ft_go_first_elem(&lfil);
		while (lfil->right)
		{
			print_line(lfil, options, max_c);
			lfil = lfil->right;
		}
		print_line(lfil, options, max_c);
		if (ldir)
			ft_putendl("");
		ft_putchar('\0');
	}
}
