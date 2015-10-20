/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 15:33:57 by sde-toda          #+#    #+#             */
/*   Updated: 2015/07/20 17:07:39 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static void	delete_line(char **line, int *i)
{
	while (*i)
	{
		*line = delete_char(*line, *i);
		(*i)--;
	}
	tputs(tgetstr("cd", NULL), 0, outputc);
}

static void	check_up_key(t_shell *shell, char **line, int *i)
{
	if (shell->history->left)
	{
		delete_line(line, i);
		free(*line);
		*line = ft_strdup(shell->history->data);
		shell->history = shell->history->left;
		*i = ft_strlen(*line);
		write(1, *line, *i);
	}
	else
	{
		delete_line(line, i);
		free(*line);
		*line = ft_strdup(shell->history->data);
		*i = ft_strlen(*line);
		write(1, *line, *i);
	}
}

static void	check_down_key(t_shell *shell, char **line, int *i)
{
	delete_line(line, i);
	if (shell->history->right)
	{
		free(*line);
		shell->history = shell->history->right;
		*line = ft_strdup(shell->history->data);
		*i = ft_strlen(*line);
	}
	write(1, *line, *i);
}

void		check_history(t_shell *shell, char **line, char buffer[3], int *i)
{
	if (shell->history)
	{
		if (UP || DOWN)
		{
			if (UP)
				check_up_key(shell, line, i);
			if (DOWN)
				check_down_key(shell, line, i);
		}
	}
}
