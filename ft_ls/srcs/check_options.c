/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 20:19:33 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 21:20:26 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			check_double_tiret(char *first_arg)
{
	if (first_arg[1] == '-' && first_arg[2] != '\0')
		get_error(1, 0, first_arg);
	if (ft_strstr(&first_arg[1], "--"))
		get_error(1, 0, first_arg);
}

static void			check_options4(char *first_arg, int i, t_opts *options)
{
	if (!O && first_arg[i] == 'o')
	{
		O = 1;
		ONE = 0;
	}
	if (!GF && first_arg[i] == 'F')
	{
		GF = 1;
		P = 0;
	}
	if (!P && first_arg[i] == 'p')
	{
		P = 1;
		GF = 0;
	}
}

static void			check_options3(char *first_arg, int i, t_opts *options)
{
	if (!C && first_arg[i] == 'c')
	{
		C = 1;
		U = 0;
		GU = 0;
	}
	if (!U && first_arg[i] == 'u')
	{
		U = 1;
		C = 0;
		GU = 0;
	}
	if (!GU && first_arg[i] == 'U')
	{
		GU = 1;
		C = 0;
		U = 0;
	}
	if (!L && first_arg[i] == 'l')
	{
		L = 1;
		ONE = 0;
	}
	check_options4(first_arg, i, options);
}

static void			check_options2(char *first_arg, int i, t_opts *options)
{
	if (!GA)
		GA = (first_arg[i] == 'A') ? 1 : 0;
	if (!F)
		F = (first_arg[i] == 'f') ? 1 : 0;
	if (!GT)
		GT = (first_arg[i] == 'T') ? 1 : 0;
	if (!G && first_arg[i] == 'g')
	{
		G = 1;
		ONE = 0;
	}
	if (!GS)
		GS = (first_arg[i] == 'S') ? 1 : 0;
	if (!ONE && first_arg[i] == '1')
	{
		ONE = 1;
		G = (G == 1) ? 2 : 0;
		O = (O == 1) ? 2 : 0;
		L = 0;
	}
	check_options3(first_arg, i, options);
}

void				check_options(char *first_arg, t_opts *options)
{
	int				i;

	i = 0;
	check_double_tiret(first_arg);
	while (first_arg[++i])
	{
		if (first_arg[i] == '-' && first_arg[i - 1] != '-')
			get_error(1, i, first_arg);
		if (strchr("-AFRSTUacdfgloprtu1", first_arg[i]))
		{
			if (!D)
				D = (first_arg[i] == 'd') ? 1 : 0;
			if (!REC)
				REC = (first_arg[i] == 'R') ? 1 : 0;
			if (!A)
				A = (first_arg[i] == 'a') ? 1 : 0;
			if (!REV)
				REV = (first_arg[i] == 'r') ? 1 : 0;
			if (!T)
				T = (first_arg[i] == 't') ? 1 : 0;
			check_options2(first_arg, i, options);
		}
		else
			get_error(1, i, first_arg);
	}
}
