/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 15:32:31 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/09 20:33:00 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

const t_error	g_errors[] =
{
	{NONE, ""},
	{UNKNOWN, "command not found"},
	{UNEXEC, "permission denied"},
	{SIGQUIT, "quit"},
	{SIGILL, "illegal hardware instruction"},
	{SIGTRAP, "trace trap"},
	{SIGABRT, "abort"},
	{SIGEMT, "EMT instruction"},
	{SIGFPE, "floating point instruction"},
	{SIGKILL, "killed"},
	{SIGBUS, "bus error"},
	{SIGSEGV, "segmentation fault"},
	{SIGSYS, "invalid system call"},
	{SIGPIPE, "invalid pipe"},
	{SIGALRM, "arlarm"},
	{SIGTERM, "terminated"},
	{SIGURG, "urgent condition on socket"},
	{SIGSTOP, "suspended (signal)"},
	{SIGTSTP, "suspended"},
	{SIGCONT, "continued"},
	{SIGCHLD, "child status changed"},
	{SIGTTIN, "suspended (tty input)"},
	{SIGTTOU, "suspend (tty output)"},
	{SIGIO, "I/O possible on a descriptor"},
	{SIGXCPU, "cpu limit exceeded"},
	{SIGXFSZ, "file size limit exceeded"},
	{SIGVTALRM, "virtual time alarm"},
	{SIGPROF, "profile signal"},
	{SIGWINCH, "terminal size changed"},
	{SIGINFO, "status request"},
	{SIGUSR1, "user-defined signal 1"},
	{SIGUSR2, "user-defined signal 2"}
};

void			treat_error(t_shell *shell, char *msg)
{
	if (shell->error && shell->error < 31)
	{
		ft_putstr("ft_minishell1 : ");
		ft_putstr(g_errors[shell->error].message);
		ft_putstr(shell->error < 3 ? " : " : "\t");
		ft_putendl(msg);
	}
	shell->error = NONE;
}
