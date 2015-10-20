/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_built.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 17:44:17 by sde-toda          #+#    #+#             */
/*   Updated: 2015/10/12 13:53:18 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void		getbins(t_shell *shell)
{
	free_table(shell->tab);
	fill_hashtable(shell);
}

static void		check_arg(char *command, t_shell *shell)
{
	int			len;
	t_tree		*temp;

	len = 0;
	temp = shell->env;
	ft_go_first_elem(&temp);
	while (command && command[len] != '=' && command[len])
		len++;
	while (command && temp)
	{
		if (!ft_strncmp(temp->data, command, len + 1))
		{
			ft_strdel(&temp->data);
			temp->data = ft_strdup(command);
			if (!ft_strncmp(command, "PATH=", len + 1))
			{
				ft_freetab(&shell->path);
				shell->path = ft_strsplit(command + 5, ':');
				getbins(shell);
			}
			return ;
		}
		temp = temp->right;
	}
	ft_insert_elem_r(&shell->env, ft_new_elem(command));
}

static int		insert_arg(char **command, t_shell *shell)
{
	char		*ret;
	char		*temp;
	char		*new_line;

	ret = NULL;
	new_line = ft_strdup(command[0]);
	temp = ft_strjoin(new_line, "=");
	if (command[1] && !(ret = ft_strchr(*command, '=')))
	{
		ft_strdel(&new_line);
		new_line = ft_strdup(temp);
		ft_strdel(&temp);
		temp = ft_strjoin(new_line, command[1]);
	}
	if (ret)
	{
		ft_strdel(&new_line);
		ft_strdel(&temp);
		return (-1);
	}
	ft_strdel(&new_line);
	check_arg(temp, shell);
	ft_strdel(&temp);
	return (0);
}

static void		stock_args(t_shell *shell)
{
	int			i;
	t_tree		*temp;

	i = 1;
	temp = shell->env;
	ft_go_first_elem(&temp);
	while ((temp = temp->right))
		i++;
	temp = shell->env;
	ft_go_first_elem(&temp);
	ft_freetab(&shell->char_env);
	shell->char_env = (char**)ft_xmalloc(sizeof(char*) * (i + 1));
	i = 0;
	while (temp)
	{
		if (ft_strstr(temp->data, "PATH="))
		{
			ft_freetab(&shell->path);
			shell->path = ft_strsplit(temp->data + 5, ':');
			getbins(shell);
		}
		shell->char_env[i++] = ft_strdup(temp->data);
		temp = temp->right;
	}
	shell->char_env[i] = NULL;
}

int				setenv_built(char **command, t_shell *shell)
{
	int			ret;
	int			args;

	ret = 0;
	args = 0;
	if (!command[0])
		env_built(command, shell);
	else
	{
		while (!ret && *command && !ft_strchr(*command, '='))
		{
			ret = insert_arg(command, shell);
			if (shell->env->data[ft_strlen(shell->env->data) - 1] != '=')
				command++;
			command++;
			args++;
		}
		if (ret || (*command && ft_strchr(*command, '=')))
			ft_putendl("setenv : Syntax Error.");
		if (args)
			stock_args(shell);
	}
	return (1);
}
