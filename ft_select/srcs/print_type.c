/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:10:52 by sde-toda          #+#    #+#             */
/*   Updated: 2015/04/01 20:43:33 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		get_color(struct stat fstats)
{
	if (S_ISREG(fstats.st_mode))
	{
		if (((fstats.st_mode & (S_IEXEC >> 0)) ||
			(fstats.st_mode & (S_IEXEC >> 3)) ||
			(fstats.st_mode & (S_IEXEC > 6))) && S_ISREG(fstats.st_mode))
			ft_putstrtty(RED);
		else
			ft_putstrtty(WHI);
	}
	else if (S_ISDIR(fstats.st_mode))
		ft_putstrtty(BLU);
	else if (S_ISLNK(fstats.st_mode))
		ft_putstrtty(PUR);
	else if (S_ISCHR(fstats.st_mode))
		ft_putstrtty(YEL);
	else if (S_ISSOCK(fstats.st_mode))
		ft_putstrtty(GRE);
	else if (S_ISFIFO(fstats.st_mode))
		ft_putstrtty(YEL);
	else if (S_ISBLK(fstats.st_mode))
		ft_putstrtty(CYA);
}

void			print_type(char *str)
{
	char		*test;
	struct stat fstats;
	int			is_allowd;

	test = str;
	is_allowd = 0;
	if (test[0] != '/')
	{
		test = ft_strjoin("./", test);
		is_allowd = 1;
	}
	if (lstat(test, &fstats) == 0)
	{
		get_color(fstats);
		ft_putstrtty(str);
		if (S_ISDIR(fstats.st_mode) && str[ft_strlen(str) - 1] != '/')
			outputc('/');
	}
	else
		ft_putstrtty(str);
	if (is_allowd)
		free(test);
}
