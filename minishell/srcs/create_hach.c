/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hach.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 18:03:50 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/12 20:12:06 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_hach		*create_hach(char *s, char *path)
{
	t_hach	*new;

	new = (t_hach*)ft_xmalloc(sizeof(t_hach));
	new->path = ft_strdup(path);
	new->data = ft_strdup(s);
	new->next = NULL;
	return (new);
}
