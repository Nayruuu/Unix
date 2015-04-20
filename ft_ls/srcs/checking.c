/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 20:19:33 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 19:39:53 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					is_type(char *name, t_opts *options)
{
	struct stat		ftest;
	struct stat		ltest;

	if (lstat(name, &ftest) < 0)
		return (ERROR);
	else
	{
		if (S_ISLNK(ftest.st_mode) && !L && !REC)
		{
			if (lstat(get_path_link(name), &ltest) == 0)
			{
				if (S_ISDIR(ltest.st_mode))
					return (0);
				else
					return (1);
			}
		}
		return (S_ISDIR(ftest.st_mode) ? 0 : 1);
	}
}

void				check_files(char **argv, int argc, t_opts *options)
{
	int				i;
	struct stat		ftest;

	i = 0;
	CHECK = 0;
	while (i < argc)
	{
		if (lstat(argv[i], &ftest) < 0)
		{
			CHECK = 1;
			get_error(2, 0, argv[i]);
			ft_strclr(argv[i]);
		}
		i++;
	}
}
