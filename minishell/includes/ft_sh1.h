/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 15:08:10 by sde-toda          #+#    #+#             */
/*   Updated: 2015/09/21 22:03:04 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include <pwd.h>
# include <fcntl.h>
# include "errors.h"
# include <signal.h>
# include <dirent.h>
# include "haching.h"
# include <termcap.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include "../libft/includes/libft.h"

# define PATH "/usr/local/bin/:/usr/bin:/bin:/usr/sbin:/opt/X11/bin:/usr/texbin"

# define TAB (buffer[0] == 9)
# define RET (buffer[0] == 10)
# define DEL (buffer[0] == 127)
# define CTRL_A (buffer[0] == 1)
# define CTRL_E (buffer[0] == 5)
# define CTRL_L (buffer[0] == 12)
# define UP (buffer[0] == 27 && buffer[2] == 65)
# define DOWN (buffer[0] == 27 && buffer[2] == 66)
# define LEFT (buffer[0] == 27 && buffer[2] == 68)
# define RIGHT (buffer[0] == 27 && buffer[2] == 67)
# define CTRL_D (buffer[0] == 4 && buffer[1] == 0 && buffer[2] == 0)

# define UID_SS (fstats.st_mode & S_ISUID)
# define UID_X (fstats.st_mode & (S_IEXEC >> 0))
# define UID_S (fstats.st_mode & S_ISUID && !(fstats.st_mode & S_IXOTH))

# define GRD_SS (fstats.st_mode & S_ISGID)
# define GRD_X (fstats.st_mode & (S_IEXEC >> 3))
# define GRD_S (fstats.st_mode & S_ISGID && !(fstats.st_mode & S_IXGRP))

# define USR_SS (fstats.st_mode & S_ISVTX)
# define USR_X (fstats.st_mode & (S_IEXEC >> 6))
# define USR_S (fstats.st_mode & S_ISVTX && !(fstats.st_mode & S_IXUSR))

int						g_ctrlc;
struct winsize			g_sz;

typedef struct termios	t_termios;

typedef struct			s_shell
{
	t_tree				*env;
	char				*home;
	char				**path;
	char				*oldpwd;
	char				name[128];
	char				**char_env;
	t_termios			terminal;
	t_termios			term_save;
	enum e_error		error;
	t_hach				*tab[30][216];
	t_tree				*history;
}						t_shell;

/*
**						Shell/
**							 Shell Functions
*/

t_shell					*empty_shell(void);
t_shell					*init_shell(char **env);
t_shell					*copy_shell(t_shell *shell);
char					**get_path(char **char_env);
t_shell					*get_shell(int i, t_shell *shell);
void					destroy_shell(t_shell *shell);
void					fill_hashtable(t_shell *shell);
void					treat_error(t_shell *shell, char *msg);
void					set_term(t_termios *terminal, t_termios *term_save);

/*
**						Command/
**								Execution
*/

void					treat_tild(char **command, char *shell_home);
void					exec_command(char *exec, char **command,
						t_shell *shell);
void					treat_command(char *str, t_shell *shell);
char					*find_command(char *command, t_shell *shell);

/*
**						Builtins/
**								 Builtin execution
*/

void					handle_signal(int signal);
int						cd_built(char **command, t_shell *shell);
int						env_built(char **command, t_shell *shell);
int						is_builtin(char **command, t_shell *shell);
int						setenv_built(char **command, t_shell *shell);
int						unsetenv_built(char **command, t_shell *shell);

/*
**						Output/
**								Output Functions
*/

int						outputc(int c);
char					*read_line(t_shell *shell, int len);
int						print_prompt(t_shell const *shell);

/*
**						Edition/
**								Editing line
*/

char					*delete_char(char *line, int i);
char					*insert_char(char *line, char buffer[3], int i,
						int len);
void					editing_line(char **line, char buffer[3], int *i,
						int len);

/*
**						Completion/
**									Completion Functions
*/

void					get_directories(t_tree **list, char *line);
void					ft_sort_by_ascii(t_tree **atree, t_tree *elem);
void					get_all(t_tree **list, char **path, char *line);
char					*completion(t_shell *shell, char *line, int *i,
						t_tree **sentinelle);

/*
**						History/
**									Sh_history
*/

int						open_history(void);
void					check_history(t_shell *shell, char **line,
						char buffer[3], int *i);

#endif
