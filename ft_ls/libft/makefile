# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 13:50:01 by sde-toda          #+#    #+#              #
#    Updated: 2015/01/03 21:41:30 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GCC = gcc

CFLAGS = -Wall -Werror -Wextra -I includes/ -g3

AR = ar rc

SRCS = ft_memcmp.c ft_memmove.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c
SRCS +=	ft_memchr.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c
SRCS +=	ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c
SRCS +=	ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c
SRCS += ft_isalnum.c ft_isascii.c ft_isprint.c ft_isdigit.c ft_toupper.c
SRCS +=	ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c
SRCS +=	ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c
SRCS +=	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c
SRCS +=	ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c 
SRCS += ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c 
SRCS += ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c
SRCS += ft_lstiter.c ft_lstmap.c ft_memrealloc.c ft_strsort.c ft_xmalloc.c

OBJS = $(SRCS:.c=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	@$(GCC) -g3 $(CFLAGS) -c -o $@  $<

clean:
	 	@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

norme: 
	@norminette $(SRCS)
	@norminette "includes/"
