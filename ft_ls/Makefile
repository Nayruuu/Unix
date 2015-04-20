# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 15:40:22 by sde-toda          #+#    #+#              #
#    Updated: 2015/01/03 21:41:22 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

GCC = gcc

FLAGS = -Wall -Werror -Wextra -O2 -I includes/
LFLAGS = -L libft/ -lft

LIBFT = ./libft/libft.a
DO_LIBFT = make -C libft/
CL_LIBFT = make -C libft/ clean
FCL_LIBFT = make -C libft/ fclean

SRC = ft_ls.c checking.c get_errors.c ft_init_tree.c ft_new_elem.c 
SRC += ft_go_first_elem.c ft_insert_elem_r.c ft_insert_elem_l.c
SRC += ft_destroy_elem.c ft_destroy_tree.c check_options.c
SRC += ft_sort_by_ascii.c ft_sort_by_time.c ft_sort_by_ascii_r.c ft_sort_by_time_r.c
SRC += ft_options.c get_links.c get_rights.c get_uid_name.c get_grd_name.c 
SRC += get_size.c get_date.c print_fargv.c print_dargv.c read_dir.c
SRC += get_max_l.c get_max_u.c get_max_g.c get_max_s.c get_max_chars.c
SRC += get_total.c init_max_chars.c get_path_link.c get_major_minor.c
SRC += get_max_m.c read_rec.c print_nor.c get_attr.c not_option_d.c
SRC += ft_sort_by_size.c ft_sort_by_size_r.c get_max_length.c get_nbr_length.c

OBJ = $(SRC:.c=.o)

SRCD = srcs/
OBJD = objs/
SRCS = $(addprefix $(SRCD), $(SRC))
OBJS = $(addprefix $(OBJD), $(OBJ))

.PHONY = all clean fclean re

$(NAME): $(OBJS) $(LIBFT)
	@echo "\\033[1;36mMaking Objects..."
	$(GCC) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo "\\033[6;32mFT_LS STATUS = DONE"


$(LIBFT):
	@echo "\\033[1;36mMaking Lib..."
	@$(DO_LIBFT)

$(OBJD)%.o: $(SRCD)%.c
	@mkdir $(OBJD) 2> /dev/null || echo '' > /dev/null
	@$(GCC) $(FLAGS) -o $@ -c $<

all: $(NAME)

clean: 
		@rm -f $(OBJS)
		@rm -rf $(OBJD)
		@$(CL_LIBFT)
		@echo "\\033[2;31mCleaning Objects..."

fclean: clean
	@echo "Cleaning Libft.a and ft_ls.."
	rm -f $(NAME)
	rm -f $(LIBFT)
	@$(FCL_LBFT)

re: fclean all

norme:
	@make -C libft/ norme
	@norminette $(SRCS) 
	@norminette "includes/"
