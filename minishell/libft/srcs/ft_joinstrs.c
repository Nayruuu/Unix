/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinstrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 16:08:13 by sde-toda          #+#    #+#             */
/*   Updated: 2015/05/29 16:43:16 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_joinstrs(char **tab)
{
	int		j;
	int		i;
	int		k;
	int		len;
	char	*result;

	k = 0;
	i = -1;
	len = 0;
	while (tab[++i])
		len += ft_strlen(tab[i]);
	result = (char*)malloc(sizeof(char) * (len + i + 1));
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			result[k++] = tab[i][j];
		result[k] = ' ';
		k++;
	}
	result[k] = '\0';
	return (result);
}
