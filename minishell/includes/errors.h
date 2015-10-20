/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 17:36:50 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/09 19:42:58 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*
**					Definitions/
**								Errors
*/

enum				e_error
{
	NONE = 0,
	UNKNOWN,
	UNEXEC,
	SIGQUIT,
	SIGILL,
	SIGTRAP,
	SIGABRT,
	SIGEMT,
	SIGFPE,
	SIGKILL,
	SIGBUS,
	SIGSEGV,
	SIGSYS,
	SIGPIPE,
	SIGALRM,
	SIGTERM,
	SIGURG,
	SIGSTOP,
	SIGTSTP,
	SIGCONT,
	SIGCHLD,
	SIGTTIN,
	SIGTTOU,
	SIGIO,
	SIGXCPU,
	SIGXFSZ,
	SIGVTALRM,
	SIGPROF,
	SIGWINCH,
	SIGINFO,
	SIGUSR1,
	SIGUSR2
};

typedef struct		s_error
{
	enum e_error	error;
	const char		message[128];
}					t_error;

#endif
