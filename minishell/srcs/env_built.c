/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 16:51:58 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/13 19:14:10 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void			check_path(t_shell *shell, char *command)
{
	int				j;
	t_tree			*temp;

	j = 0;
	while (command[j] != '=')
		j++;
	if (!shell->oldpwd)
	{
		temp = shell->env;
		ft_go_first_elem(&temp);
		while (temp)
		{
			if (!ft_strncmp(temp->data, "PATH", j))
			{
				ft_freetab(&shell->path);
				shell->path = ft_strsplit(temp->data, ':');
				free_table(shell->tab);
				init_tab(shell->tab);
				fill_hashtable(shell);
			}
			temp = temp->right;
		}
	}
}

static int			stock_args(t_shell *shell)
{
	int				i;
	t_tree			*temp;

	i = 0;
	temp = shell->env;
	ft_go_first_elem(&temp);
	while (temp)
	{
		i++;
		temp = temp->right;
	}
	temp = shell->env;
	ft_go_first_elem(&temp);
	ft_freetab(&shell->char_env);
	shell->char_env = (char**)ft_xmalloc(sizeof(char*) * (i + 1));
	i = 0;
	while (temp)
	{
		shell->char_env[i++] = ft_strdup(temp->data);
		temp = temp->right;
	}
	shell->char_env[i] = NULL;
	return (0);
}

static void			exec_last(t_shell *cpy, char **command)
{
	int				i;
	char			*line;

	i = -1;
	if (!(*command))
	{
		while (cpy->char_env[++i])
			ft_putendl(cpy->char_env[i]);
	}
	else
	{
		if (!ft_strcmp(command[0], cpy->home))
		{
			ft_putstr("env: ");
			ft_putstr(cpy->home);
			ft_putendl(": Permission denied");
		}
		else
		{
			line = ft_joinstrs(command);
			treat_command(line, cpy);
			free(line);
		}
	}
}

static void			check_arg(t_shell *cpy, char *command)
{
	int				j;
	t_tree			*temp;

	j = -1;
	while (command[++j] != '=')
		temp = cpy->env;
	ft_go_first_elem(&temp);
	while (temp)
	{
		if (!ft_strncmp(temp->data, command, j))
		{
			ft_strdel(&temp->data);
			temp->data = ft_strdup(command);
			if (!ft_strncmp(command, "PATH", j))
			{
				ft_freetab(&cpy->path);
				cpy->path = ft_strsplit(command + 5, ':');
				fill_hashtable(cpy);
			}
			return ;
		}
		temp = temp->right;
	}
	ft_insert_elem_r(&cpy->env, ft_new_elem(command));
	check_path(cpy, command);
}

int					env_built(char **command, t_shell *shell)
{
	t_shell			*cpy;

	if (*command && !ft_strcmp(*command, "-i"))
	{
		cpy = get_shell(1, shell);
		command++;
	}
	else
		cpy = get_shell(2, shell);
	while (*command && ft_strchr(*command, '='))
	{
		if ((*command)[0] == '=' || (ft_strchr(*command, '=') - 1)[-1] == ' ')
		{
			shell->error = UNKNOWN;
			treat_error(shell, *command);
			destroy_shell(cpy);
			return (-1);
		}
		check_arg(cpy, *command);
		command++;
	}
	stock_args(cpy);
	exec_last(cpy, command);
	destroy_shell(cpy);
	return (1);
}
