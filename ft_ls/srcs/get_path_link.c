/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 16:42:43 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 13:09:48 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*get_path_link(char *name)
{
	int			len;
	struct stat	lstats;
	char		*linkname;

	if (lstat(name, &lstats) < 0)
		exit (1);
	if (S_ISLNK(lstats.st_mode))
	{
		linkname = (char*)ft_xmalloc(sizeof(char) * 1024);
		if (linkname == NULL)
		{
			ft_putendl_fd("insufficient memory\n", 2);
			exit (1);
		}
		if ((len = readlink(name, linkname, 1024)) < 0)
			exit (1);
		linkname[len] = '\0';
		return (linkname);
	}
	return (NULL);
}
