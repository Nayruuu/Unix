/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haching.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 23:02:40 by sde-toda          #+#    #+#             */
/*   Updated: 2015/06/12 19:45:58 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HACHING_H
# define HACHING_H

typedef struct		s_hach
{
	char			*path;
	char			*data;
	struct s_hach	*next;
}					t_hach;

void				init_tab(t_hach *tab[30][216]);
t_hach				*create_hach(char *s, char *path);
void				haching(char *s, char *path, t_hach *tab[30][216]);
void				free_table(t_hach *tab[30][216]);
char				*getbin(char *s, t_hach *tab[30][216]);

#endif
