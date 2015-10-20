/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haching.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 18:10:50 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/12 20:04:43 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void				haching(char *s, char *path, t_hach *tab[30][216])
{
	int				i;
	int				t;
	t_hach			*temp;

	i = -1;
	t = 0;
	while (s[++i])
		t += (i * s[i]) / ((i + 1) * (i + 1));
	t = (t > 215) ? 215 : t;
	if (!tab[i][t])
		tab[i][t] = create_hach(s, path);
	else
	{
		temp = tab[i][t];
		while (temp->next)
		{
			if (!ft_strcmp(s, temp->data))
				return ;
			temp = temp->next;
		}
		temp->next = create_hach(s, path);
	}
}
