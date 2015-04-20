/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:12:08 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/30 22:11:29 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_termios			init_term(t_termios *term_save)
{
	char					*name;
	struct termios			terminal;

	if (!isatty(STDIN_FILENO))
		exit (!ft_putendl_fd(ERROR_3, 2));
	if ((name = getenv("TERM")) == NULL)
		exit (!ft_putendl_fd(ERROR_1, 2));
	if (tgetent(NULL, name) == ERROR)
		exit (!ft_putendl_fd(ERROR_2, 2));
	if (tcgetattr(STDIN_FILENO, &terminal) == ERROR)
		exit (!ft_putendl_fd(ERROR_4, 2));
	if (tcgetattr(STDIN_FILENO, term_save) == ERROR)
		exit (!ft_putendl_fd(ERROR_4, 2));
	terminal.c_lflag &= ~(ICANON);
	terminal.c_lflag &= ~(ECHO);
	terminal.c_cc[VMIN] = 1;
	terminal.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &terminal) == ERROR)
		exit (!ft_putendl_fd(ERROR_5, 2));
	tputs(tgetstr("ti", NULL), 0, outputc);
	tputs(tgetstr("vi", NULL), 0, outputc);
	return (terminal);
}

static void					reload_term(t_termios term_save)
{
	tputs(tgetstr("te", NULL), 0, outputc);
	tputs(tgetstr("ve", NULL), 0, outputc);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &term_save) == ERROR)
		exit (!ft_putendl_fd(ERROR_5, 2));
}

static void					handle_z(t_termios *terminal,
		struct termios terminal_save)
{
	char					cp[2];

	cp[0] = terminal->c_cc[VSUSP];
	cp[1] = 0;
	reload_term(terminal_save);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

int							handle_term(int choice)
{
	static int				sig = 0;
	static struct termios	terminal;
	static struct termios	terminal_save;

	if (choice == 0)
		terminal = init_term(&terminal_save);
	else if (choice == 1)
		reload_term(terminal_save);
	else if (choice == 2)
		sig = 1;
	else if (choice == 3)
	{
		if (sig == 1)
		{
			sig = 0;
			return (1);
		}
	}
	else if (choice == 4)
		handle_z(&terminal, terminal_save);
	return (0);
}
