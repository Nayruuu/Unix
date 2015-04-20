/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 15:13:48 by sde-toda          #+#    #+#             */
/*   Updated: 2015/04/01 15:19:34 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void				print_elem(t_circ *list, int j, int i)
{
	tputs(tgoto(tgetstr("cm", NULL), j, i), 0, outputc);
	if (list->position == 1)
		ft_putstrtty(UNDERLINE);
	if (list->select == 1)
		ft_putstrtty(INVERSED);
	print_type(list->data);
	ft_putstrtty(EOC);
}

static void				get_window_terms(t_winsize *window)
{
	static int			ret = 0;

	if (ret == 1 && handle_term(3))
	{
		ioctl(0, TIOCGWINSZ, window);
		ret = 0;
	}
	else if (ret == 0)
	{
		ioctl(0, TIOCGWINSZ, window);
		ret = 1;
	}
}

static void				print_all(t_circ *list, int length, t_winsize window)
{
	int					i;
	int					j;

	i = 0;
	j = 0;
	while (!list->end && j < window.ws_col - length && window.ws_row >= 3)
	{
		print_elem(list, j, i);
		list = list->right;
		i++;
		if (i >= window.ws_row - 2)
		{
			i = 0;
			j = length < window.ws_col ? j + length : 0;
		}
	}
	if (j < window.ws_col - length && window.ws_row >= 3)
		print_elem(list, j, i);
}

int						init_list(t_circ *list, int row)
{
	int					count;

	count = 0;
	while (!list->position)
	{
		count++;
		list = list->right;
	}
	return (row ? count / row : 1);
}

void					print_args(t_circ *list, int length)
{
	int					i;
	int					count;
	int					nbr_elems;
	static t_winsize	window;

	i = 0;
	get_window_terms(&window);
	length = get_hori_len(length);
	nbr_elems = size_list(list);
	if (length >= window.ws_col || window.ws_row <= 3)
		ft_putstrtty("Window too small.");
	count = init_list(list, window.ws_row - 2) * (window.ws_row - 2);
	if ((nbr_elems / window.ws_row + 1) * length > window.ws_col - 1)
	{
		while (i < count)
		{
			list = list->right;
			i++;
		}
	}
	print_all(list, length, window);
}
