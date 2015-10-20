/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/04 15:42:00 by sde-toda          #+#    #+#             */
/*   Updated: 2015/07/04 16:25:40 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int				open_history(void)
{
	int			fd;

	fd = open(".sh_history", O_CREAT | O_RDWR | O_APPEND);
	chmod(".sh_history", S_IRUSR | S_IWUSR);
	return (fd);
}
