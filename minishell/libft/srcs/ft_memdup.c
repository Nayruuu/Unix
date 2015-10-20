/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 16:00:00 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/04 16:01:55 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			*ft_memdup(void *ptr, size_t size)
{
	void		*new;

	if (ptr && size)
	{
		new = ft_memalloc(size);
		if (new)
			return (ft_memcpy(new, ptr, size));
	}
	return (NULL);
}
