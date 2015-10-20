/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:53:47 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/15 14:08:08 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
		{
			i++;
			count++;
		}
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] == '\0')
			break ;
		count++;
	}
	return (count);
}

char		*ft_strspaces(char *str)
{
	int		i;
	int		k;
	char	*new;

	i = 0;
	k = 0;
	new = (char*)ft_xmalloc(sizeof(char) * (count_len(str) + 1));
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			new[k++] = str[i++];
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] == '\0')
			break ;
		new[k] = ' ';
		k++;
	}
	new[k] = '\0';
	return (new);
}
