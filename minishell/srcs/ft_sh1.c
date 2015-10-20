/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:07:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 22:04:48 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void			set_signals(int argc, char **argv)
{
	argc = (int)argc;
	argv = (char**)argv;
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
	signal(SIGTSTP, handle_signal);
}

static void			get_history(t_shell *shell)
{
	int				fd;
	char			*temp;

	fd = open_history();
	while (get_next_line(fd, &temp))
	{
		ft_insert_elem_r(&shell->history, ft_new_elem(temp));
		free(temp);
	}
}

static void			insert_history(t_shell *shell, char *line)
{
	int				i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			ft_putendl_fd(line, open_history());
			while (shell->history && shell->history->right)
				shell->history = shell->history->right;
			ft_insert_elem_r(&shell->history, ft_new_elem(line));
			break ;
		}
		i++;
	}
}

static int			treat_line(t_shell *shell)
{
	int				len;
	char			*line;

	len = 0;
	if (g_ctrlc < 2)
	{
		len = print_prompt(shell);
		g_ctrlc = 0;
	}
	else
		g_ctrlc = 0;
	if ((line = read_line(shell, len)))
	{
		treat_command(line, shell);
		insert_history(shell, line);
		free(line);
		return (1);
	}
	else
	{
		destroy_shell(shell);
		return (0);
	}
}

int					main(int argc, char **argv, char **env)
{
	t_shell			*shell;

	g_ctrlc = 0;
	shell = init_shell(env);
	get_history(shell);
	set_signals(argc, argv);
	set_term(&shell->terminal, &shell->term_save);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &shell->terminal) == ERROR)
		exit(1);
	while (1)
	{
		if (treat_line(shell))
			continue ;
		else
			break ;
	}
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &(shell->term_save));
	return (0);
}
