/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_term.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 17:03:29 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 22:05:53 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void				set_term(t_termios *terminal, t_termios *term_save)
{
	char			*name;

	if (!isatty(STDIN_FILENO))
		exit(1);
	if ((name = getenv("TERM")))
	{
		if (tgetent(NULL, name) == ERROR)
			exit(1);
	}
	else
	{
		if (tgetent(NULL, "xterm-256color") == ERROR)
			exit(1);
	}
	if ((tcgetattr(STDIN_FILENO, terminal) == ERROR) ||
		(tcgetattr(STDIN_FILENO, term_save) == ERROR))
		exit(1);
	terminal->c_lflag &= ~(ICANON);
	terminal->c_lflag &= ~(ECHO);
	terminal->c_cc[VMIN] = 1;
	terminal->c_cc[VTIME] = 0;
}
