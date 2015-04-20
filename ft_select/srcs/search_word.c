/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 18:15:35 by sde-toda          #+#    #+#             */
/*   Updated: 2015/04/01 22:11:27 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		swap(t_circ **position, t_circ **temp)
{
	(*position)->position = 0;
	(*temp)->position = 1;
	*position = *temp;
}

static void		del_char(char *str, int *i)
{
	*i -= 2;
	str[*i] = '\0';
}

static void		dont_find(t_circ **list, t_circ **pos, char buffer[3], int t)
{
	if (t == 0)
		search_word(list, pos, buffer, 1);
}

static void		clear_stock(char *stock, int *i)
{
	*i = 0;
	stock[1] = '\0';
}

char			*search_word(t_circ **list, t_circ **pos, char buffer[3], int t)
{
	int			c;
	t_circ		*temp;
	static int	i = 0;
	static char	stock[1024];

	c = size_list(*list);
	temp = *list;
	if ((ft_isprint(stock[i] = buffer[0]) || (buffer[0] == 9 && i)) && c > 1)
	{
		stock[++i] = '\0';
		if (buffer[0] == 9)
			del_char(stock, &i);
		while (c-- && ft_strncmp(temp->data, stock, i))
			temp = temp->right;
		if (!ft_strncmp(temp->data, stock, i))
			swap(pos, &temp);
		else
		{
			i = 0;
			dont_find(list, pos, buffer, t);
		}
		return (stock);
	}
	clear_stock(stock, &i);
	return (NULL);
}
