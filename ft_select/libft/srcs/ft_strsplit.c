/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:14:30 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/20 22:33:28 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	full_tab(char **tab, char const *s, char c, int words)
{
	int			j;
	size_t		i;

	j = 0;
	i = ft_strlen(s) - 1;
	while (words > 0)
	{
		while (s[i] == c && i > 0)
			i--;
		j = i;
		while (s[j] != c && j >= 0)
			j--;
		if (ft_strnew(i - j + 1))
			tab[words - 1] = ft_strsub(s, j + 1, i - j);
		else
			tab = NULL;
		tab[words - 1][i - j] = '\0';
		i = j;
		words--;
	}
}

static	int		count_words(char const *s, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int			words;
	char		**new_tab;

	if (s && c)
	{
		words = count_words(s, c);
		if ((new_tab = (char**)ft_xmalloc((words + 1) * sizeof(char*))))
		{
			new_tab[words] = NULL;
			full_tab(new_tab, s, c, words);
			return (new_tab);
		}
	}
	return (NULL);
}
