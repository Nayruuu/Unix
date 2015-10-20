/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 21:02:39 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/13 17:18:56 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static char		*into(char *line, int i)
{
	char		*part1;
	char		*part2;
	char		*new_line;

	part1 = ft_strsub(line, 0, i - 1);
	part2 = ft_strsub(line, i, (int)ft_strlen(line) - i);
	new_line = ft_strjoin(part1, part2);
	ft_strdel(&part1);
	ft_strdel(&part2);
	ft_strdel(&line);
	return (new_line);
}

static void		clean_char(char *line, int i)
{
	tputs(tgetstr("dm", NULL), 0, outputc);
	tputs(tgetstr("le", NULL), 0, outputc);
	tputs(tgetstr("dc", NULL), 0, outputc);
	tputs(tgetstr("ed", NULL), 0, outputc);
	tputs(tgetstr("sc", NULL), 0, outputc);
	if (line)
	{
		while (i <= (int)ft_strlen(line))
		{
			outputc(line[i - 1]);
			i++;
		}
	}
	tputs(tgetstr("rc", NULL), 0, outputc);
}

char			*delete_char(char *line, int i)
{
	char		*new_line;

	new_line = NULL;
	tputs(tgetstr("vi", NULL), 0, outputc);
	tputs(tgetstr("cd", NULL), 0, outputc);
	if (line && i != (int)ft_strlen(line))
		new_line = into(line, i);
	else if (i > 1)
	{
		new_line = ft_strsub(line, 0, ft_strlen(line) - 1);
		if (ft_strlen(new_line) == 0)
			ft_strdel(&new_line);
		ft_strdel(&line);
	}
	else
		ft_strdel(&line);
	clean_char(new_line, i);
	tputs(tgetstr("ve", NULL), 0, outputc);
	return (new_line);
}
