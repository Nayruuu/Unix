/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:50:11 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/05 20:51:30 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_line(char **save, char **line, int fd)
{
	int				ret;
	char			*ptr;
	char			r_str[BUFF_SIZE + 1];

	if (!(*line = ft_strdup(*save)))
		return (ERROR);
	while (!(ptr = ft_strchr(*line, '\n')) &&
			(ret = read(fd, r_str, BUFF_SIZE)) > 0)
	{
		r_str[ret] = '\0';
		if (!(*line = ft_memrealloc(*line, ft_strlen(*line) + BUFF_SIZE)))
			return (ERROR);
		ft_strcat(*line, r_str);
	}
	if (ptr && ret != ERROR)
	{
		*ptr = '\0';
		ptr++;
		ft_strdel(save);
		if (!(*save = ft_strdup(ptr)))
			return (ERROR);
	}
	if (ret == 0 && !(ptr))
		return (0);
	return ((ret == ERROR) ? ERROR : 1);
}

int					get_next_line(int fd, char **line)
{
	static	char	*save = NULL;

	if (fd == ERROR || BUFF_SIZE < 0 || !line)
		return (ERROR);
	if (save == NULL)
	{
		if (!(save = ft_strnew(BUFF_SIZE + 1)))
			return (ERROR);
	}
	return (get_line(&save, line, fd));
}
