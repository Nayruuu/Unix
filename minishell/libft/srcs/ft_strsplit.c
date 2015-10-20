/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:14:30 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/15 14:01:54 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				count_words(char const *str, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *str, char c)
{
	int			i;
	int			j;
	int			k;
	char		**tab;

	i = 0;
	k = 0;
	tab = (char**)ft_xmalloc(sizeof(char*) * (count_words(str, c) + 1));
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (!str[i])
			break ;
		j = i;
		while (str[i] != c && str[i])
			i++;
		tab[k] = ft_strsub(str, j, i - j);
		k++;
	}
	tab[k] = NULL;
	return (tab);
}
