/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 18:41:09 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 22:04:33 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void			doing_child(char *exec, char **command, t_shell *shell)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &(shell->term_save));
	execve(exec, command, shell->char_env);
	shell->error = UNKNOWN;
	treat_error(shell, *command);
	exit(1);
}

static void			treat_status(char **command, int status, t_shell *shell)
{
	char			*line;

	if (WIFSTOPPED(status))
		status = SIGTSTP;
	if (status && status != 2)
	{
		shell->error = status;
		line = ft_joinstrs(command);
		treat_error(shell, line);
		g_ctrlc = 2;
		free(line);
		print_prompt(shell);
	}
	if (status == 2)
		ft_putendl("");
}

void				exec_command(char *exec, char **command, t_shell *shell)
{
	pid_t			pid;
	int				status;

	if (!access(exec, X_OK | F_OK))
	{
		pid = fork();
		if (pid == 0)
			doing_child(exec, command, shell);
		if (pid > 0)
		{
			waitpid(pid, &status, WUNTRACED | WCONTINUED);
			treat_status(command, status, shell);
			tcsetattr(STDIN_FILENO, TCSADRAIN, &(shell->terminal));
		}
		shell->error = NONE;
	}
	else if (!exec)
		treat_error(shell, command[0]);
}
