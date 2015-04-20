/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 13:44:54 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/27 14:16:20 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			reload_term(struct termios term_save)
{
	tputs(tgetstr("ve", NULL), 0, outputc);
	tcsetattr(0, 0, &term_save);
}
