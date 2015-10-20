/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_built.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 10:57:31 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 22:06:22 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static int		unset_arg(char *command, t_shell *shell)
{
	t_tree		*temp;
	const int	len = ft_strlen(command);

	temp = shell->env;
	ft_go_first_elem(&temp);
	while (temp)
	{
		if (!ft_strncmp(temp->data, command, len) && temp->data[len] == '=')
		{
			if (temp->data[len - 1] == '=' && temp->data[len] != '=')
			{
				temp = temp->right;
				continue ;
			}
			ft_destroy_elem(&temp);
			shell->env = temp;
			return (1);
		}
		temp = temp ? temp->right : temp;
	}
	return (0);
}

static void		stock_args(t_shell *shell)
{
	int			i;
	t_tree		*temp;

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
		shell->char_env[i] = ft_strdup(temp->data);
		i++;
		temp = temp->right;
	}
	shell->char_env[i] = NULL;
}

int				unsetenv_built(char **command, t_shell *shell)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	if (!command[0])
	{
		ft_putendl("unsetenv: Too few arguments.");
		return (-1);
	}
	else
	{
		while (command[i])
		{
			ret += unset_arg(command[i], shell);
			i++;
		}
		if (ret)
			stock_args(shell);
	}
	return (1);
}
