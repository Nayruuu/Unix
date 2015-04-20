/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 14:46:19 by sde-toda          #+#    #+#             */
/*   Updated: 2015/04/01 20:08:51 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <signal.h>
# include <termcap.h>
# include <termios.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"

# define ERROR (-1)
# define ERROR_1 "./ft_select: can't find terminal's name."
# define ERROR_2 "./ft_select: can't find terminfo database."
# define ERROR_3 "./ft_select: fd is not associated with a terminal."
# define ERROR_4 "./ft_select: can't get terminal informations."
# define ERROR_5 "./ft_select: can't set terminal informations."

# define EOC "\033[0;0m"
# define WHI "\033[1;37m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define BLU "\033[1;34m"
# define PUR "\033[35m"
# define YEL "\033[33m"
# define CYA "\033[36m"
# define UNDERLINE "\033[4m"
# define INVERSED "\033[7m"

typedef struct termios	t_termios;
typedef struct winsize	t_winsize;

/*
**					Circ/
**						Circular list management
*/

typedef struct		s_circ
{
	int				end;
	int				begin;
	int				select;
	int				position;
	char			*data;
	struct s_circ	*left;
	struct s_circ	*right;
}					t_circ;

int					size_list(t_circ *list);
t_circ				*create_new_elem(char *data);
void				insert_new_elem(t_circ **list, t_circ *new_elem);

/*
**					Output/
**						Output functions
*/

int					outputc(int c);
void				print_type(char *str);
int					ft_putstrtty(char *str);
void				print_searching(char *str);

/*
**					Algorithm/
**						Algorithm Functions
*/

int					get_hori_len(int length);
void				print_args(t_circ *list, int length);
int					select_list(t_circ **list, int length);
void				select_all(t_circ **list, int choice, int select);
char				*search_word(t_circ **list, t_circ **pos, char buf[3],
		int t);

/*
**					Environment/
**							Environment Management
*/

int					handle_term(int choice);
void				handle_signal(int signal);
void				move_side(t_circ **position, int key);

#endif
