/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 21:42:49 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 22:03:48 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static int		exit_built(char **command)
{
	int			i;

	i = 0;
	while (command[++i])
	{
		if (!ft_isdigit(command[i][0]))
		{
			ft_putendl("exit: Expression Syntax.");
			return (-1);
		}
	}
	if (i > 2)
	{
		ft_putendl("exit: Expression Syntax.");
		return (-1);
	}
	else
	{
		ft_putendl("exit");
		i == 2 ? exit(ft_atoi(command[1])) : exit(0);
	}
	return (1);
}

int				is_builtin(char **command, t_shell *shell)
{
	if (!ft_strcmp(command[0], "exit"))
		return (exit_built(command));
	else if (!ft_strcmp(command[0], "env"))
		return (env_built(&command[1], shell));
	else if (!ft_strcmp(command[0], "setenv"))
		return (setenv_built(&command[1], shell));
	else if (!ft_strcmp(command[0], "unsetenv"))
		return (unsetenv_built(&command[1], shell));
	else if (!ft_strcmp(command[0], "cd"))
		return (cd_built(&command[1], shell));
	return (0);
}
