/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_searching.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 20:06:11 by sde-toda          #+#    #+#             */
/*   Updated: 2015/04/01 22:43:01 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			print_searching(char *str)
{
	t_winsize	window;

	ioctl(0, TIOCGWINSZ, &window);
	if (str && window.ws_row >= 3)
	{
		tputs(tgetstr("ho", NULL), 0, outputc);
		tputs(tgetstr("ll", NULL), 0, outputc);
		tputs(tgoto(tgetstr("cm", NULL), 0, window.ws_row), 0, outputc);
		ft_putstrtty("searching : ");
		ft_putstrtty(str);
	}
}
