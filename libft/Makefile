# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 09:42:00 by nokiddy           #+#    #+#              #
#    Updated: 2018/09/11 09:42:03 by nokiddy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS  = -Wall -Werror -Wextra
SRC := ft_isdigit.c	ft_strcmp.c	ft_strlen.c	ft_toupper.c ft_memset.c \
ft_strcpy.c	ft_strncpy.c ft_strchr.c ft_strdup.c ft_tolower.c \
ft_memmove.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_strcat.c \
ft_strnew.c ft_strncat.c ft_strlcat.c ft_strstr.c ft_strncmp.c \
ft_atoi.c ft_itoa.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_memchr.c ft_memcmp.c ft_strrchr.c ft_strnstr.c ft_putchar.c ft_putstr.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_memalloc.c \
ft_putnbr.c ft_putnbr_fd.c ft_memdel.c ft_strdel.c ft_strclr.c ft_striter.c \
ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
ft_strjoin.c ft_lstnew.c ft_lstiter.c ft_lstadd.c ft_strtrim.c ft_lstdelone.c \
ft_lstdel.c ft_lstmap.c ft_strsplit.c get_next_line.c ft_list_reverse.c \
ft_list_size.c
HDR := libft.h
OBJS	:= ${SRC:.c=.o}
NAME = libft.a


all: $(NAME)

$(NAME): $(SRC)
	gcc $(CFLAGS) -c $^ -I $(HDR)
	ar -cr $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(wildcard *.o)

fclean: clean
	/bin/rm -f $(NAME)

re: 
	@$(MAKE) fclean 
	@$(MAKE) all

.PHONY: all clean fclean re
