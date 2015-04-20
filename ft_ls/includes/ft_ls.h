/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 14:18:11 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/03 19:50:38 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <dirent.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>

# define ERROR (-1)

# define MAXL max_c->max_l
# define MAXU max_c->max_u
# define MAXG max_c->max_g
# define MAXS max_c->max_s
# define MAXT max_c->max_t
# define MAXM max_c->max_m

# define L options->l
# define REC options->rec
# define A options->a
# define REV options->rev
# define T options->t
# define D options->d
# define GA options->ga
# define P options->p
# define F options->f
# define GT options->gt
# define C options->c
# define U options->u
# define G options->g
# define GU options->gu
# define GS options->gs
# define ONE options->one
# define O options->o
# define GF options->gf
# define CHECK options->check

# define NAME content->d_name
# define F_NAME lfiles->data
# define D_NAME ldirec->data
# define RIGHTS fstats.st_mode

/*
**			Renaming/
**						Renainming Types
*/

typedef long unsigned int		t_lui;

/*
**			Tree List/
**						Tree list operations
*/

typedef struct		s_tree
{
	char			*data;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

void				ft_go_first_elem(t_tree **tree);
void				ft_destroy_tree(t_tree **tree);
void				ft_destroy_elem(t_tree **elem);
void				ft_insert_elem_r(t_tree **atree, t_tree *elem);
void				ft_insert_elem_l(t_tree **atree, t_tree *elem);
t_tree				*ft_init_tree(void);
t_tree				*ft_new_elem(char *data);

/*
**			Max_chars/
**						Getting Max Chars Informations
*/

typedef struct		s_max
{
	int				max_t;
	unsigned int	max_l;
	unsigned int	max_u;
	unsigned int	max_g;
	unsigned int	max_s;
	unsigned int	max_m;
}					t_max;

unsigned int		get_nbr_length(int n);
int					get_max_l(int max_l, struct stat fstats);
int					get_max_u(int max_u, struct stat fstats);
int					get_max_g(int max_g, struct stat fstats);
int					get_max_s(int max_s, struct stat fstats);
int					get_max_m(int max_m, struct stat fstats);
t_max				*init_max_chars(void);

/*
**			Options/
**					  Options Functions
*/

typedef struct		s_options
{
	int				l;
	int				rec;
	int				a;
	int				rev;
	int				t;
	int				d;
	int				ga;
	int				p;
	int				f;
	int				gt;
	int				c;
	int				u;
	int				g;
	int				gu;
	int				gs;
	int				one;
	int				o;
	int				check;
	int				gf;
}					t_opts;

void				option_trs(t_tree **lfil, t_tree **ldir, char *cont,
		t_opts *options);
void				not_option_d(int i, int argc, char **argv,
		t_opts *options);
int					option_l(char *name, t_opts *options, t_max *max_c);
void				get_max_chars(char *name, t_max *max_c, t_opts *options);
char				*get_path_link(char *name);
int					get_total(int max_t, struct stat fstats);
void				get_attr(const char *name);
void				get_rights(struct stat fstats);
void				get_links(struct stat fstats, int max_l);
void				get_uid_name(t_opts *options, struct stat fstats,
		int max_u);
void				get_grd_name(t_opts *options, struct stat fstats,
		int max_g);
void				get_size(struct stat fstats, int max_s, int spaces);
void				get_date(struct stat fstats, t_opts *options);
void				get_major_minor(struct stat fstats, int max_m);

/*
**			Check/
**					Checking Functions
*/

int					is_type(char *name, t_opts *options);
void				check_options(char *first_arg, t_opts *options);
void				check_files(char **argv, int argc, t_opts *options);

/*
**			Printing/
**					  Printing Functions
*/

void				print_nor(const t_tree *lfiles, t_opts *options,
		t_max *max_c, int check_d);
void				read_rec(char *name, t_opts *options);
t_tree				*read_dir(char *name, t_tree **ldirec, t_opts *optionsi,
		t_max *max_c);
void				print_dargv(t_tree *ldirec, int check_f, t_opts *options);
void				print_fargv(t_tree *lfil, t_tree *t_ldir,
		t_opts *opts, t_max *max);

/*
**			Sort/
**					Sorting Functions
*/

void				ft_sort_by_ascii(t_tree **atree, t_tree *elem);
void				ft_sort_by_ascii_r(t_tree **atree, t_tree *elem);
void				ft_sort_by_size(t_tree **atree, t_tree *elem);
void				ft_sort_by_size_r(t_tree **atree, t_tree *elem);
void				ft_sort_by_time(t_tree **atree, t_tree *elem,
		t_opts *options);
void				ft_sort_by_time_r(t_tree **atree, t_tree *elem,
		t_opts *options);

/*
** 			Errors/
**					Errors Functions
*/

void				get_error(int err_nbr, int nbr_char, char *arg);

#endif
