/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 11:47:43 by sde-toda          #+#    #+#             */
/*   Updated: 2014/12/29 11:49:46 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		get_nbr_length(int n)
{
	int				mem;
	unsigned int	nbr_chars;

	mem = n;
	nbr_chars = 0;
	if (mem <= 0)
		nbr_chars = 1;
	while (mem)
	{
		mem = mem - (mem % 10);
		mem = mem / 10;
		nbr_chars++;
	}
	return (nbr_chars);
}
