/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 20:19:33 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 20:43:37 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*get_name(char *name)
{
	char		*new;

	if ((new = ft_strrchr(name, '/')))
	{
		new++;
		return (new);
	}
	else
		return (name);
}

void			get_error(int err_nbr, int nbr_char, char *arg)
{
	if (err_nbr == 1)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(arg[nbr_char], 2);
		ft_putstr_fd("\nusage: ft_ls ", 2);
		ft_putstr_fd("[-AFRSTUabcdfgloprtu1]", 2);
		ft_putstr_fd(" [file ...]\n", 2);
		exit (1);
	}
	else if (err_nbr == 2)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(get_name(arg), 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
}
