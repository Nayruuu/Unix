/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 10:13:41 by sde-toda          #+#    #+#             */
/*   Updated: 2015/04/01 17:44:53 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int			check_column(t_circ *position, int row)
{
	int				count;
	int				count2;
	t_circ			*temp;

	count = 0;
	count2 = 0;
	temp = position;
	while (!position->end && count < row - 2)
	{
		count++;
		position = position->right;
	}
	count = position->end ? 0 : 2;
	while (count2 < row - 2)
	{
		count2++;
		temp = temp->right;
	}
	if (count >= row - 2 || !ft_strcmp(temp->data, position->data))
		return (1);
	else
		return (0);
}

static int			check_left_side(t_circ *position, int row)
{
	int				count;
	t_circ			*temp;

	count = 0;
	temp = position;
	while (!temp->begin)
	{
		temp = temp->left;
		count++;
	}
	if (count < row - 2)
		return (1);
	else
		return (0);
}

void				move_side(t_circ **position, int key)
{
	int				count;
	t_winsize		window;
	t_circ			*temp;

	count = -1;
	temp = (*position)->right;
	ioctl(0, TIOCGWINSZ, &window);
	while ((*position)->right && ++count < window.ws_row - 2 &&
			ft_strcmp(temp->data, (*position)->data))
		temp = temp->right;
	if (((count < window.ws_row - 2 || !(*position)->right)) ||
		(key == 67 && !check_column(*position, window.ws_row)) ||
		(key == 68 && check_left_side(*position, window.ws_row)))
		tputs(tgetstr("bl", NULL), 0, outputc);
	else if ((*position)->right)
	{
		count = 0;
		(*position)->position = 0;
		while (count < window.ws_row - 2)
		{
			(*position) = (key == 67) ? (*position)->right : (*position)->left;
			count++;
		}
		(*position)->position = 1;
	}
}
