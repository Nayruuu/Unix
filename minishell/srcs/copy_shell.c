/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 22:53:00 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 22:02:48 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static char		**copy_tab(char **tab)
{
	int			i;
	char		**new;

	i = 0;
	while (tab[i])
		i++;
	new = (char**)ft_xmalloc(sizeof(char*) * (i + 1));
	i = 0;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

t_shell			*copy_shell(t_shell *shell)
{
	t_tree		*temp;
	t_shell		*new;

	new = (t_shell*)ft_xmalloc(sizeof(t_shell));
	ft_strcpy(new->name, shell->name);
	new->error = shell->error;
	new->home = ft_strdup(shell->home);
	new->env = ft_init_tree();
	temp = shell->env;
	ft_go_first_elem(&temp);
	while (temp)
	{
		ft_insert_elem_r(&new->env, ft_new_elem(temp->data));
		temp = temp->right;
	}
	new->path = NULL;
	new->history = NULL;
	new->char_env = copy_tab(shell->char_env);
	init_tab(new->tab);
	return (new);
}
