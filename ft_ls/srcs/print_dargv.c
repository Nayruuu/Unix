/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dargv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 23:39:13 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 12:05:10 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_dir(t_tree *ldirec, int check_f, t_opts *options)
{
	if (check_f == 1 || ldirec->right || ldirec->left)
	{
		ft_putstr(D_NAME);
		ft_putendl(":");
	}
	read_rec(D_NAME, options);
	if (ldirec->right)
		ft_putendl("");
	ft_putchar('\0');
}

void			print_dargv(t_tree *ldirec, int check_f, t_opts *options)
{
	if (ldirec)
	{
		ft_go_first_elem(&ldirec);
		while (ldirec->right)
		{
			print_dir(ldirec, check_f, options);
			ldirec = ldirec->right;
		}
		print_dir(ldirec, check_f, options);
	}
}
