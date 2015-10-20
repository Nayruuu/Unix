/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 20:22:26 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/08 16:59:25 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static char		*into(char *line, char buffer[3], int i)
{
	char		*temp;
	char		*part1;
	char		*part2;
	char		*new_line;

	part1 = ft_strsub(line, 0, i);
	part2 = ft_strsub(line, i, (int)ft_strlen(line) - i);
	new_line = ft_strjoin(part1, buffer);
	temp = ft_strdup(new_line);
	free(new_line);
	new_line = ft_strjoin(temp, part2);
	ft_strdel(&temp);
	ft_strdel(&line);
	ft_strdel(&part1);
	ft_strdel(&part2);
	return (new_line);
}

char			*insert_char(char *line, char buffer[3], int i, int len)
{
	char		*new_line;

	if (line && i != (int)ft_strlen(line))
		new_line = into(line, buffer, i);
	else
	{
		new_line = ft_strjoin(line, buffer);
		ft_strdel(&line);
	}
	tputs(tgetstr("im", NULL), 0, outputc);
	tputs(tgetstr("ic", NULL), 0, outputc);
	write(1, &buffer[0], 1);
	if (!((len + i + 1) % (g_sz.ws_col)))
	{
		tputs(tgetstr("ic", NULL), 0, outputc);
		write(1, " ", 1);
		tputs(tgetstr("le", NULL), 0, outputc);
	}
	tputs(tgetstr("ei", NULL), 0, outputc);
	return (new_line);
}
