/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 16:17:31 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/13 19:08:23 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static char			*is_exec(t_shell *shell, char *command)
{
	struct stat		fstats;

	if (ft_strchr(command, '/') && stat(command, &fstats) == 0)
	{
		if (UID_SS || UID_S || UID_X)
			return (command);
		else if (GRD_SS || GRD_S || GRD_X)
			return (command);
		else if (USR_SS || USR_S || USR_X)
			return (command);
		else
			shell->error = UNEXEC;
	}
	return (NULL);
}

char				**getting_path(t_shell *shell)
{
	if (!shell->path)
	{
		shell->path = get_path(shell->char_env);
		fill_hashtable(shell);
	}
	return (shell->path);
}

char				*find_command(char *command, t_shell *shell)
{
	int				i;
	char			*exec;

	i = -1;
	exec = NULL;
	getting_path(shell);
	if ((exec = getbin(command, shell->tab)))
		return (exec);
	shell->error = shell->error == NONE ? UNKNOWN : shell->error;
	return ((exec = is_exec(shell, command)) ? exec : NULL);
}

void				treat_command(char *str, t_shell *shell)
{
	int				i;
	char			*exec;
	char			**command;
	char			**commands;
	char			*cleared_line;

	i = 0;
	cleared_line = ft_strspaces(str);
	commands = ft_strsplit(cleared_line, ';');
	while (commands[i])
	{
		command = ft_strsplit(commands[i], ' ');
		treat_tild(command, shell->home);
		if (!is_builtin(command, shell))
		{
			exec = find_command(command[0], shell);
			exec_command(exec, command, shell);
			if (exec && ft_strcmp(exec, command[0]))
				ft_strdel(&exec);
		}
		ft_freetab(&command);
		i++;
	}
	ft_freetab(&commands);
	ft_strdel(&cleared_line);
}
