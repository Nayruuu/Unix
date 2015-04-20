/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rights.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 11:04:11 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 20:58:06 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				get_type_file(struct stat fstats)
{
	if (S_ISREG(RIGHTS))
		ft_putchar('-');
	else if (S_ISDIR(RIGHTS))
		ft_putchar('d');
	else if (S_ISBLK(RIGHTS))
		ft_putchar('b');
	else if (S_ISLNK(RIGHTS))
		ft_putchar('l');
	else if (S_ISCHR(RIGHTS))
		ft_putchar('c');
	else if (S_ISFIFO(RIGHTS))
		ft_putchar('p');
	else if (S_ISSOCK(RIGHTS))
		ft_putchar('s');
}

void				get_uid_rights(struct stat fstats)
{
	ft_putchar((RIGHTS & (S_IREAD >> 0)) ? 'r' : '-');
	ft_putchar((RIGHTS & (S_IWRITE >> 0)) ? 'w' : '-');
	if ((RIGHTS & S_ISUID && !(RIGHTS & S_IXOTH)) != 0)
		ft_putchar('S');
	else if ((RIGHTS & S_ISUID) != 0)
		ft_putchar('s');
	else
		ft_putchar((RIGHTS & (S_IEXEC >> 0)) ? 'x' : '-');
}

void				get_grd_rights(struct stat fstats)
{
	ft_putchar((RIGHTS & (S_IREAD >> 3)) ? 'r' : '-');
	ft_putchar((RIGHTS & (S_IWRITE >> 3)) ? 'w' : '-');
	if ((RIGHTS & S_ISGID && !(RIGHTS & S_IXGRP)) != 0)
		ft_putchar('S');
	else if ((RIGHTS & S_ISGID) != 0)
		ft_putchar('s');
	else
		ft_putchar((RIGHTS & (S_IEXEC >> 3)) ? 'x' : '-');
}

void				get_usr_rights(struct stat fstats)
{
	ft_putchar((RIGHTS & (S_IREAD >> 6)) ? 'r' : '-');
	ft_putchar((RIGHTS & (S_IWRITE >> 6)) ? 'w' : '-');
	if ((RIGHTS & S_ISVTX && !(RIGHTS & S_IXUSR)) != 0)
		ft_putchar('T');
	else if ((RIGHTS & S_ISVTX) != 0)
		ft_putchar('t');
	else
		ft_putchar((RIGHTS & (S_IEXEC >> 6)) ? 'x' : '-');
}

void				get_rights(struct stat fstats)
{
	get_type_file(fstats);
	get_uid_rights(fstats);
	get_grd_rights(fstats);
	get_usr_rights(fstats);
}
