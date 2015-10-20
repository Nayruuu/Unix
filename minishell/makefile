# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 15:40:22 by sde-toda          #+#    #+#              #
#    Updated: 2015/10/12 13:51:35 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

GCC = gcc

FLAGS = -Wall -Werror -Wextra -O3 -I includes/ -g
LFLAGS = -O3 -L libft/ -lft -ltermcap
LIBFT = ./libft/libft.a
DO_LIBFT = make -C libft/
CL_LIBFT = make -C libft/ clean
FCL_LIBFT = make -C libft/ fclean

SRC = ft_sh1.c treat_command.c builtins.c treat_error.c env_built.c
SRC += init_shell.c destroy_shell.c setenv_built.c unsetenv_built.c
SRC += cd_built.c treat_tild.c copy_shell.c handle_signal.c read_line.c
SRC += print_prompt.c outputc.c insert_char.c delete_char.c set_term.c
SRC += empty_shell.c exec_command.c get_path.c get_shell.c editing_line.c
SRC += init_tab.c create_hach.c haching.c getbin.c free_table.c fill_hashtable.c
SRC += completion.c ft_sort_by_ascii.c get_all.c get_directories.c open_history.c
SRC += check_history.c

OBJ = $(SRC:.c=.o)

SRCD = srcs/
OBJD = objs/
SRCS = $(addprefix $(SRCD), $(SRC))
OBJS = $(addprefix $(OBJD), $(OBJ))

.PHONY = all clean fclean re norme

$(NAME): $(LIBFT) $(OBJS)
	@$(GCC) -o $(NAME) $(OBJS) $(LFLAGS) $(MLX_FLAGS)
	@echo "\\033[0;32mFT_SH1 STATUS = DONE"
	@sleep 2
	@clear

$(LIBFT):
	@clear
	@echo "\\033[0;32mMaking Lib..."
	@sleep 1
	@$(DO_LIBFT)
	@printf "\\033[0;32mLIBFT STATUS = DONE\n"
	@sleep 1
	@clear
	@echo "\\033[0;32mMaking Objects..."
	@sleep 1

$(OBJD)%.o: $(SRCD)%.c
	@mkdir $(OBJD) 2> /dev/null || echo '' > /dev/null
	@$(GCC) $(FLAGS) -o $@ -c $<
	@printf "\\033[1;37m%-23s -\\033[0;32m->     \\033[1;34m%s\n" "$<" "$@"

all: $(NAME)

clean:	
		@clear
		@rm -f $(OBJS)
		@rm -rf $(OBJD)
		@$(FCL_LIBFT)	
		@echo "\\033[2;31mCleaning Objects..."
		@sleep 2
		@clear


fclean: clean
	@echo "Cleaning Libft.a and ft_sh1.."
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@$(FCL_LBFT)
	@sleep 2
	@clear

re: fclean
	@echo ""
	@make all

norme:
	@norminette libft/**/*.[hc]
	@norminette **/*.[hc]
