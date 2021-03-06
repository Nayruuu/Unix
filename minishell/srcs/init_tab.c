/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 18:00:58 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/12 19:46:54 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void			init_tab(t_hach *tab[30][216])
{
	int			i;
	int			j;

	i = -1;
	while (++i < 30)
	{
		j = -1;
		while (++j < 216)
		{
			tab[i][j] = NULL;
		}
	}
}
