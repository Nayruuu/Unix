/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 12:03:26 by sde-toda          #+#    #+#             */
/*   Updated: 2015/07/20 16:06:49 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstrc(char const *s, char const *color, char const *mode)
{
	if (mode)
		ft_putstr(mode);
	ft_putstr(color);
	ft_putstr(s);
	ft_putstr(EOC);
}
