/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:01:50 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/31 14:21:52 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void						handle_cont(void)
{
	signal(SIGTSTP, handle_signal);
	handle_term(0);
	ioctl(0, TIOCSTI, "");
}

void						handle_signal(int signal)
{
	if (signal == SIGINT || signal == SIGQUIT)
	{
		handle_term(1);
		ft_putendl("^C");
		exit (1);
	}
	if (signal == SIGTSTP)
		handle_term(4);
	if (signal == SIGCONT)
		handle_cont();
	if (signal == SIGWINCH)
	{
		handle_term(2);
		ioctl(0, TIOCSTI, "");
	}
	if (signal == SIGTERM)
	{
		handle_term(1);
		ft_putendl("ft_select got killed.");
		exit (1);
	}
}
