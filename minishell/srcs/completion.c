/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 19:25:31 by sde-toda          #+#    #+#             */
/*   Updated: 2015/07/04 11:44:01 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static int			count_words(char *line)
{
	int				temp;
	int				count;

	temp = 0;
	count = 0;
	while (line[temp])
	{
		while (line[temp] == ' ')
			temp++;
		if (line[temp] == '\0')
			break ;
		count++;
		if (line[temp] == ';')
			count = 0;
		while (line[temp] != ' ' && line[temp])
			temp++;
	}
	return (count);
}

static void			get_new(char ***line, t_tree *sentinelle)
{
	char			*new;

	new = NULL;
	if (!(**line))
		**line = ft_strdup("");
	else
	{
		new = ft_strdup(**line);
		ft_strdel(*line);
		**line = ft_strjoin(new, sentinelle->data);
		ft_strdel(&new);
	}
}

static void			reset_line(t_tree *list, t_tree **sentinelle,
					char **line, int *i)
{
	int				temp;

	temp = *i;
	while (temp > 0 && (*line)[temp - 1] != ' ' && (*line)[temp - 1] != '/')
	{
		*line = delete_char(*line, temp);
		temp--;
	}
	if (!(*line))
		*line = ft_strdup("");
	else if ((*line)[temp] == ' ')
		temp++;
	tputs(tgetstr("sc", NULL), 0, outputc);
	get_new(&line, *sentinelle);
	*sentinelle = (*sentinelle)->right;
	if (!(*sentinelle))
		*sentinelle = list;
	tputs(tgetstr("rc", NULL), 0, outputc);
	*i = ft_strlen(*line);
	write(1, &(*line)[temp], (*i - temp));
}

static char			*get_word(char *line, int *i)
{
	int				temp;

	temp = *i;
	while (line[temp] == ' ')
		temp++;
	while (line[temp] != ' ' && temp)
		temp--;
	if (line[temp] == ' ')
		temp++;
	return (ft_strsub(&line[temp], 0, ft_strlen(line) - temp));
}

char				*completion(t_shell *shell, char *line, int *i,
					t_tree **sentinelle)
{
	char			*word;
	static t_tree	*list;

	if (!(*sentinelle))
		ft_destroy_tree(&list);
	if (line && *i == (int)ft_strlen(line) && count_words(line))
	{
		word = get_word(line, i);
		if (!shell->path)
		{
			shell->path = get_path(shell->char_env);
			fill_hashtable(shell);
		}
		if (!(*sentinelle))
		{
			(count_words(line) == 1 && line[ft_strlen(line) - 1] != ' ') ?
			get_all(&list, shell->path, word) : get_directories(&list, word);
			*sentinelle = list;
		}
		if (list)
			reset_line(list, sentinelle, &line, i);
		ft_strdel(&word);
	}
	return (line);
}
