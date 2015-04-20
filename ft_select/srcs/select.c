/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 15:45:15 by sde-toda          #+#    #+#             */
/*   Updated: 2015/04/01 22:33:51 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		select_one(t_circ **position)
{
	(*position)->select = (*position)->select ? 0 : 1;
	if ((*position)->right)
	{
		(*position)->position = 0;
		*position = (*position)->right;
		(*position)->position = 1;
	}
}

static void		move(t_circ **position, int dir)
{
	if ((*position)->right && (*position)->left)
	{
		(*position)->position = 0;
		*position = dir == 1 ? (*position)->right : (*position)->left;
		(*position)->position = 1;
	}
	else
		tputs(tgetstr("bl", NULL), 0, outputc);
	if ((*position)->right == (*position)->left)
		tputs(tgetstr("bl", NULL), 0, outputc);
}

static void		delete_elem(t_circ **position, t_circ **list)
{
	if ((*position)->right == NULL)
	{
		free (*position);
		*list = NULL;
		return ;
	}
	if ((*position)->end == 1)
		(*position)->left->end = 1;
	if ((*position)->begin == 1)
	{
		(*position)->right->begin = 1;
		*list = (*position)->right;
		if ((*list)->right == *list)
			*list = NULL;
	}
	(*position)->right->left = (*position)->left;
	(*position)->left->right = (*position)->right;
	free((*position)->data);
	free (*position);
	*position = (*position)->right;
	if (*position)
		(*position)->position = 1;
}

static int		select_key(t_circ **list, t_circ **position, char buffer[3])
{
	static int	select = 1;

	if (buffer[0] == 32)
		select_one(position);
	else if (buffer[0] == 27 && buffer[2] == 66)
		move(position, 1);
	else if (buffer[0] == 27 && buffer[2] == 65)
		move(position, 0);
	else if (buffer[0] == 10)
		return (1);
	else if (buffer[0] == 127 ||
			(buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 51))
		delete_elem(position, list);
	else if (buffer[0] == 27 && (buffer[2] == 67 || buffer[2] == 68))
		move_side(position, buffer[2]);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 70)
	{
		select_all(list, 1, select);
		select = select ? 0 : 1;
	}
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 54)
		select_all(list, 2, select);
	return (0);
}

int				select_list(t_circ **list, int length)
{
	char		buffer[3];
	t_circ		*position;
	char		*tab;

	tab = NULL;
	position = *list;
	while (*list && (buffer[0] != 27 || buffer[2] != 0))
	{
		tputs(tgetstr("ho", NULL), 0, outputc);
		tputs(tgetstr("cd", NULL), 0, outputc);
		print_args(*list, length);
		print_searching(tab);
		ft_bzero(buffer, 3);
		read(0, buffer, 3);
		tab = search_word(list, &position, buffer, 0);
		if (select_key(list, &position, buffer) == 1)
			return (1);
	}
	return (0);
}
