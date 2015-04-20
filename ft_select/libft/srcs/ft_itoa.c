/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:51:19 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 22:27:36 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *overflow(int n)
{
	char	*new;

	new = NULL;
	if (n < 0)
	{
		new = ft_strnew(11);
		ft_strcpy(new, "-2147483648");
	}
	else if (n > 0)
	{
		new = ft_strnew(10);
		ft_strcpy(new, "2147483647");
	}
	return (new);
}

static char	*convert(char *new, int n, int nbr_chars)
{
	new[nbr_chars] = '\0';
	if (n == 0)
		new[0] = '0';
	else
	{
		if (n < 0)
		{
			new[0] = '-';
			n = -n;
		}
		while (n)
		{
			new[nbr_chars - 1] = (n % 10) + 48;
			n = n - (n % 10);
			n = n / 10;
			nbr_chars--;
		}
	}
	return (new);
}

char		*ft_itoa(int n)
{
	int		mem;
	int		nbr_chars;
	char	*new;

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
	if (n == 2147483647 || n == -2147483648)
		return (overflow(n));
	new = ft_strnew(nbr_chars);
	if (new)
	{
		new = convert(new, n, nbr_chars);
		return (new);
	}
	else
		return (NULL);
}
