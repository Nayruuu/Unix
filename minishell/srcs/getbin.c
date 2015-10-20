/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getbin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 18:14:26 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/13 11:50:10 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char			*getbin2(t_hach *hach)
{
	char		*bin;
	char		*bin2;

	bin = ft_strjoin(hach->path, "/");
	bin2 = ft_strjoin(bin, hach->data);
	free(bin);
	return (bin2);
}

char			*getbin(char *s, t_hach *tab[30][216])
{
	int			i;
	int			t;
	t_hach		*temp;

	i = -1;
	t = 0;
	while (s[++i])
		t += (i * s[i]) / ((i + 1) * (i + 1));
	t = t > 215 ? 215 : t;
	if (tab[i][t] && ft_strcmp(tab[i][t]->data, s))
	{
		temp = tab[i][t];
		while (temp)
		{
			if (!ft_strcmp(temp->data, s))
				return (getbin2(temp));
			temp = temp->next;
		}
	}
	else if (tab[i][t] && !ft_strcmp(tab[i][t]->data, s))
		return (getbin2(tab[i][t]));
	return (NULL);
}
