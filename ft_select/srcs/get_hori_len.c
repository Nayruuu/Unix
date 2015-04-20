/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hori_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 01:41:06 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/31 01:54:57 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_len2(int length)
{
	if (length <= 95)
		return (95);
	else if (length <= 103)
		return (103);
	else if (length <= 111)
		return (111);
	else if (length <= 119)
		return (119);
	else if (length <= 127)
		return (127);
	else
		return (length + 2);
}

int			get_hori_len(int length)
{
	if (length <= 7)
		return (8);
	else if (length <= 15)
		return (15);
	else if (length <= 23)
		return (23);
	else if (length <= 31)
		return (31);
	else if (length <= 39)
		return (39);
	else if (length <= 47)
		return (47);
	else if (length <= 55)
		return (55);
	else if (length <= 63)
		return (63);
	else if (length <= 71)
		return (71);
	else if (length <= 79)
		return (79);
	else if (length <= 87)
		return (87);
	else
		return (get_len2(length));
}
