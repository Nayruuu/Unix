/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 16:51:58 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/12 23:33:13 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_shell		*get_shell(int i, t_shell *shell)
{
	t_shell			*cpy;

	if (i == 1)
		cpy = empty_shell();
	else
		cpy = copy_shell(shell);
	cpy->terminal = shell->terminal;
	cpy->term_save = shell->term_save;
	return (cpy);
}
