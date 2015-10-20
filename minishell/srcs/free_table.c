/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 18:57:27 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/12 22:53:08 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void		destroy_chain(t_hach **tab)
{
	t_hach		*temp;
	t_hach		*temp2;

	temp = *tab;
	while (temp)
	{
		ft_strdel(&(temp->data));
		ft_strdel(&(temp->path));
		temp2 = temp->next;
		free(temp);
		temp = NULL;
		temp = temp2;
	}
}

void			free_table(t_hach *tab[128][216])
{
	int			i;
	int			j;

	i = -1;
	while (++i < 30)
	{
		j = -1;
		while (++j < 216)
		{
			if (tab[i][j])
			{
				destroy_chain((&tab[i][j]));
				tab[i][j] = NULL;
			}
		}
	}
}
