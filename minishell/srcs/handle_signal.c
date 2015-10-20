/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 19:33:32 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/09 00:35:39 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void				handle_signal(int signal)
{
	const char		buffer[3] = {0, 0, 0};

	if (signal == SIGINT || signal == SIGQUIT)
	{
		g_ctrlc = 1;
		ioctl(0, TIOCSTI, buffer);
	}
	else if (signal == SIGTSTP)
		signal = (int)signal;
}
