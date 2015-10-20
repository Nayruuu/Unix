/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 15:49:39 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 22:05:37 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int				outputc(int c)
{
	int			fd;

	fd = open("/dev/tty", O_NOCTTY | O_WRONLY);
	if (isatty(fd))
		write(fd, &c, 1);
	close(fd);
	return (1);
}
