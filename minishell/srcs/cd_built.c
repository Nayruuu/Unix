/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_built.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 12:31:27 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 22:04:22 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void		get_oldpwd(t_shell *shell)
{
	char		dir[128];

	if (shell->oldpwd)
		free(shell->oldpwd);
	getcwd(dir, 128);
	shell->oldpwd = ft_strdup(dir);
}

static void		modify_pwd(char *command, t_shell *shell)
{
	int			i;
	char		*save;

	i = -1;
	while (shell->char_env[++i])
	{
		if (!ft_strncmp(shell->char_env[i], "PWD", 3))
		{
			save = ft_strdup(&shell->char_env[i][3]);
			break ;
		}
	}
	i = -1;
	get_oldpwd(shell);
	command ? chdir(command) : chdir(shell->home);
	while (shell->char_env[++i])
	{
		if (!ft_strncmp(shell->char_env[i], "OLDPWD", 6))
		{
			free(shell->char_env[i]);
			shell->char_env[i] = ft_strjoin("OLDPWD", save);
			free(save);
			break ;
		}
	}
}

static void		replace(char **command, t_shell *shell)
{
	int			i;

	i = -1;
	while (shell->char_env[++i])
	{
		if (!ft_strncmp(shell->char_env[i], "OLDPWD", 6))
		{
			ft_putendl(&shell->char_env[i][7]);
			*command = ft_strdup(&shell->char_env[i][7]);
			break ;
		}
	}
	if (shell->oldpwd)
	{
		free(*command);
		*command = ft_strdup(shell->oldpwd);
	}
}

static int		check_command(char *command)
{
	struct stat	fstats;

	if (stat(command, &fstats) == 0)
	{
		if (S_ISDIR(fstats.st_mode))
		{
			if (UID_SS || UID_S || UID_X)
				return (1);
			if (GRD_SS || GRD_S || GRD_X)
				return (1);
			if (USR_SS || USR_S || USR_X)
				return (1);
			else
				ft_putstr("cd: Permission denied: ");
		}
		else
			ft_putstr("cd: not a directory: ");
	}
	else
		ft_putstr("cd: no such file or directory: ");
	ft_putendl(command);
	return (0);
}

int				cd_built(char **command, t_shell *shell)
{
	int			i;
	char		dir[128];

	i = 0;
	if (command[1] && command[0])
		ft_putendl("cd: Too many arguments.");
	else
	{
		if (*command && !ft_strcmp(*command, "-"))
			replace(command, shell);
		if (*command && !check_command(*command))
			return (-1);
		modify_pwd(*command, shell);
		while (shell->char_env[i])
		{
			if (!ft_strncmp(shell->char_env[i], "PWD", 3))
			{
				free(shell->char_env[i]);
				shell->char_env[i] = ft_strjoin("PWD=", getcwd(dir, 128));
				break ;
			}
			i++;
		}
	}
	return (1);
}
