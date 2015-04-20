# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 13:50:01 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/19 11:17:00 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GCC = gcc

CFLAGS = -Wall -Werror -Wextra -O3 -I includes/

AR = ar rc

SRC = ft_memcmp.c ft_memmove.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c
SRC += ft_memchr.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c
SRC += ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c
SRC += ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c
SRC += ft_isalnum.c ft_isascii.c ft_isprint.c ft_isdigit.c ft_toupper.c
SRC += ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c
SRC += ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c
SRC += ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c
SRC += ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c 
SRC += ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c 
SRC += ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c
SRC += ft_lstiter.c ft_lstmap.c ft_memrealloc.c ft_strsort.c ft_xmalloc.c
SRC += ft_inject_tab.c ft_go_first_elem.c ft_destroy_tree.c ft_destroy_elem.c
SRC += ft_insert_elem_l.c ft_insert_elem_r.c ft_init_tree.c ft_new_elem.c
SRC += ft_max_number.c ft_abs.c ft_factorial.c ft_isblank.c ft_islower.c
SRC += ft_ispunct.c ft_isspace.c ft_isupper.c

OBJ = $(SRC:.c=.o)

SRCD = srcs/
OBJD = objs/
SRCS = $(addprefix $(SRCD), $(SRC))
OBJS = $(addprefix $(OBJD), $(OBJ))

TEST = 0

.PHONY = all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJD)%.o: $(SRCD)%.c
	@mkdir $(OBJD) 2> /dev/null || echo "" > /dev/null
	@$(GCC) -g3 $(CFLAGS) -o $@ -c  $<
	@printf "\\033[1;37m%-23s -\\033[0;32m->     \\033[1;34m%s\n" "$<" "$@"

clean:
		@clear
	 	@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)


re: fclean all

norme: 
	@norminette $(SRCS)
	@norminette "includes/"
