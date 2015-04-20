/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 19:06:31 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/27 21:17:11 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			outputc(int c)
{
	int		fd;

	fd = open("/dev/tty", O_NOCTTY | O_WRONLY);
	if (isatty(fd))
		write(fd, &c, 1);
	close (fd);
	return (1);
}

int			ft_putstrtty(char *str)
{
	int		fd;

	fd = open("/dev/tty", O_NOCTTY | O_WRONLY);
	if (isatty(fd))
		write(fd, str, ft_strlen(str));
	close (fd);
	return (1);
}
