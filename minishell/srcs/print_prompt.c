/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/07 12:52:43 by sde-toda          #+#    #+#             */
/*   Updated: 2015/07/04 14:15:23 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int					print_prompt(t_shell const *shell)
{
	char			dir[128];
	int				len;

	len = 0;
	ft_putstrc("[", BLU, HIG);
	ft_putstrc(shell->name, GRE, NULL);
	len += ft_strlen(shell->name);
	ft_putstrc(":", BLU, HIG);
	if (ft_strstr(getcwd(dir, 128), shell->home))
	{
		ft_putstrc("~", WHI, HIG);
		ft_putstrc(&(ft_strstr(getcwd(dir, 128),
		shell->home))[ft_strlen(shell->home)], WHI, HIG);
		len += ft_strlen(&(ft_strstr(getcwd(dir, 128),
		shell->home))[ft_strlen(shell->home)]) + 1;
	}
	else
	{
		ft_putstrc(getcwd(dir, 128), WHI, HIG);
		len += ft_strlen(getcwd(dir, 128));
	}
	ft_putstrc("] ", WHI, HIG);
	len += 4;
	return (len);
}
