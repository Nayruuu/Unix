/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:07:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 22:05:27 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static char			*get_home(char **char_env)
{
	int				i;
	struct stat		fstats;

	i = 0;
	while (char_env[i])
	{
		if (!ft_strncmp(char_env[i], "HOME", 4))
			if (stat(&char_env[i][5], &fstats) == 0)
				if (S_ISDIR(fstats.st_mode))
					return (ft_strdup(&char_env[i][5]));
		i++;
	}
	return (ft_strdup(getpwuid(getuid())->pw_dir));
}

static int			set_tree(t_shell *shell, char **env)
{
	int				i;

	i = -1;
	while (env[++i])
	{
		ft_insert_elem_r(&shell->env, ft_new_elem(env[i]));
		if (ft_strstr(env[i], "SHLVL"))
			shell->env->data[6]++;
		if (ft_strstr(env[i], "SHELL"))
		{
			free(shell->env->data);
			shell->env->data = ft_strdup("SHELL=ft_minishell1");
		}
	}
	return (i);
}

static void			fill_env(char **shell_env, t_tree *shellenv)
{
	int				i;

	i = 0;
	ft_go_first_elem(&shellenv);
	while (shellenv)
	{
		shell_env[i++] = ft_strdup(shellenv->data);
		shellenv = shellenv->right;
	}
	shell_env[i] = NULL;
}

t_shell				*init_shell(char **env)
{
	int				i;
	t_shell			*shell;

	i = -1;
	shell = (t_shell*)ft_xmalloc(sizeof(t_shell));
	gethostname(shell->name, sizeof(shell->name));
	shell->name[ft_getchar(shell->name, '.')] = '\0';
	shell->env = ft_init_tree();
	i = set_tree(shell, env);
	shell->char_env = (char**)ft_xmalloc(sizeof(char*) * (i + 1));
	shell->error = NONE;
	fill_env(shell->char_env, shell->env);
	shell->oldpwd = NULL;
	shell->home = get_home(shell->char_env);
	shell->history = ft_init_tree();
	init_tab(shell->tab);
	return (shell);
}
