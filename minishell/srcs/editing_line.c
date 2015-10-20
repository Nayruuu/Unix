/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 19:09:01 by sde-toda          #+#    #+#             */
/*   Updated: 2015/07/04 17:10:03 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void			editing_line(char **line, char buffer[3], int *i, int len)
{
	ioctl(0, TIOCGWINSZ, &g_sz);
	if (LEFT && *i > 0)
	{
		(*i)--;
		tputs(tgetstr("le", NULL), 0, outputc);
	}
	if (RIGHT && *line && *i < (int)ft_strlen(*line))
	{
		(*i)++;
		if (!((len + *i) % (g_sz.ws_col)))
			tputs(tgetstr("do", NULL), 0, outputc);
		else
			tputs(tgetstr("nd", NULL), 0, outputc);
	}
	if (DEL && *line && *i)
	{
		*line = delete_char(*line, *i);
		(*i)--;
	}
	if (ft_isprint(buffer[0]))
	{
		*line = insert_char(*line, buffer, *i, len);
		(*i)++;
	}
}
