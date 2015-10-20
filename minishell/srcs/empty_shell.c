/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 17:15:46 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 22:02:31 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_shell				*empty_shell(void)
{
	t_shell			*shell;

	shell = (t_shell*)ft_xmalloc(sizeof(t_shell));
	shell->env = NULL;
	shell->path = ft_strsplit("/usr/local/bin:/usr/bin:/bin:\
								/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin", ':');
	shell->char_env = NULL;
	shell->oldpwd = NULL;
	shell->home = ft_strdup(getpwuid(getuid())->pw_dir);
	shell->error = NONE;
	shell->history = NULL;
	init_tab(shell->tab);
	fill_hashtable(shell);
	return (shell);
}
