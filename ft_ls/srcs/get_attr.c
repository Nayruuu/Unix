/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 15:53:09 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/31 11:44:22 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				get_attr(const char *name)
{
	int				i;
	acl_t			my_acl;

	my_acl = acl_get_link_np(name, ACL_TYPE_EXTENDED);
	if (my_acl)
	{
		if ((i = listxattr(name, NULL, 255, XATTR_NOFOLLOW) > 0))
			ft_putchar('@');
		else
			ft_putchar('+');
		ft_putchar(' ');
	}
	else if ((i = listxattr(name, NULL, 255, XATTR_NOFOLLOW) > 0))
	{
		ft_putchar('@');
		ft_putchar(' ');
	}
	else
		ft_putstr("  ");
}
