/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 01:12:13 by sde-toda          #+#    #+#             */
/*   Updated: 2015/07/20 16:08:31 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include <stdio.h>

static void			clearing_screen(t_shell *shell, char *line, int i)
{
	int				temp;
	int				len;

	if (line)
		len = ft_strlen(line);
	tputs(tgetstr("cl", NULL), 0, outputc);
	print_prompt(shell);
	if (line)
		write(1, line, len);
	temp = i;
	while (line && temp < len)
	{
		tputs(tgetstr("le", NULL), 0, outputc);
		temp++;
	}
}

static void			moving_cursor(char *line, char buffer[3], int *i, int len)
{
	int				length;

	ioctl(0, TIOCGWINSZ, &g_sz);
	if (line)
		length = ft_strlen(line);
	if (CTRL_A)
	{
		while (*i > 0)
		{
			(*i)--;
			tputs(tgetstr("le", NULL), 0, outputc);
		}
	}
	else
	{
		while (line && *i < length)
		{
			(*i)++;
			if (!((len + *i) % g_sz.ws_col))
				tputs(tgetstr("do", NULL), 0, outputc);
			else
				tputs(tgetstr("nd", NULL), 0, outputc);
		}
	}
}

static char			*return_line(char *line, char buffer[3])
{
	ft_putendl("");
	if (g_ctrlc)
	{
		free(line);
		return (ft_strdup(""));
	}
	if (RET && !line)
		return (ft_strdup(""));
	else
		return (CTRL_D ? NULL : line);
}

char				*read_line(t_shell *shell, int len)
{
	int				i;
	char			*line;
	char			buffer[3];
	t_tree			*sentinelle;

	i = 0;
	line = NULL;
	sentinelle = NULL;
	while (!RET && !CTRL_D && !g_ctrlc)
	{
		ft_bzero(buffer, 3);
		read(0, buffer, 3);
		editing_line(&line, buffer, &i, len);
		if (TAB)
			line = completion(shell, line, &i, &sentinelle);
		else
			sentinelle = NULL;
		if (CTRL_L)
			clearing_screen(shell, line, i);
		else if (CTRL_A || CTRL_E)
			moving_cursor(line, buffer, &i, len);
		check_history(shell, &line, buffer, &i);
	}
	return (return_line(line, buffer));
}
