/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 14:46:08 by sde-toda          #+#    #+#             */
/*   Updated: 2015/04/01 19:19:54 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>

static t_circ		*get_args(int argc, char **argv, int *length)
{
	int				i;
	t_circ			*new;
	int				len_str;

	i = 1;
	new = NULL;
	while (i < argc)
	{
		len_str = ft_strlen(argv[i]);
		if (len_str > *length)
			*length = len_str;
		insert_new_elem(&new, create_new_elem(argv[i]));
		i++;
	}
	return (new);
}

static void			print_selected(t_circ *list)
{
	int				is_here;

	is_here = 0;
	while (!list->end)
	{
		if (list->select)
		{
			if (is_here)
				ft_putstr(" ");
			ft_putstr(list->data);
			is_here = 1;
		}
		list = list->right;
	}
	if (list->select)
	{
		if (is_here)
			ft_putstr(" ");
		is_here = 1;
		ft_putstr(list->data);
	}
	if ((is_here || ((list->right == list || !list->right) && list->select)))
		ft_putendl("");
}

static void			no_args(void)
{
	ft_putendl_fd("ft_select: no specified argument", 2);
	ft_putendl_fd("usage: ./ft_select [arg1 arg2 ... argN]", 2);
}

int					main(int argc, char **argv)
{
	t_circ			*list;
	int				length;
	int				ret;

	length = 0;
	if (argc >= 2)
	{
		handle_term(0);
		signal(SIGINT, handle_signal);
		signal(SIGTSTP, handle_signal);
		signal(SIGCONT, handle_signal);
		signal(SIGQUIT, handle_signal);
		signal(SIGTERM, handle_signal);
		signal(SIGWINCH, handle_signal);
		list = get_args(argc, argv, &length);
		ret = select_list(&list, length);
		tputs(tgetstr("ho", NULL), 0, outputc);
		tputs(tgetstr("cd", NULL), 0, outputc);
		handle_term(1);
		if (ret)
			print_selected(list);
	}
	else
		no_args();
	return (0);
}
