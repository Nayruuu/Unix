/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inject_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 12:47:07 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/04 14:16:15 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_inject_tab(char *tab, char *injection, int position)
{
	size_t		size1;
	size_t		size2;
	char		*new_tab;

	if (!injection && !tab)
		return (NULL);
	if (!injection || (injection && !injection[0]))
		return (tab);
	if (!tab || (tab && !tab[0]))
		return (injection);
	size1 = ft_strlen(tab);
	size2 = ft_strlen(injection);
	new_tab = ft_xmalloc(size1 + size2);
	ft_memcpy(new_tab, tab, position);
	ft_memcpy(&new_tab[position], injection, size2);
	ft_memcpy(&new_tab[position + size2], &tab[position], size2 + 2 - position);
	return (new_tab);
}
