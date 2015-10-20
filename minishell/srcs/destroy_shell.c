/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 16:27:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/07/04 16:52:48 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void		destroy_shell(t_shell *shell)
{
	if (shell)
	{
		if (shell->env)
			ft_destroy_tree(&shell->env);
		if (shell->char_env)
			ft_freetab(&shell->char_env);
		if (shell->path)
			ft_freetab(&shell->path);
		if (shell->history)
			ft_destroy_tree(&shell->history);
		free_table(shell->tab);
		ft_strdel(&shell->home);
		free(shell);
		shell = NULL;
	}
}
