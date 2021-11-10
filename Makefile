# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fathjami <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 12:08:53 by fathjami          #+#    #+#              #
#    Updated: 2021/11/10 16:57:01 by fathjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
FLAGS= -Wall -Wextra -Werror -I libft.h
NAME=libft.a
FILES= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_strlen \
       ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp \
       ft_strnstr ft_strlcpy ft_strlcat ft_atoi \
       ft_memset ft_bzero ft_memmove ft_memchr ft_memcmp \
       ft_calloc ft_strdup ft_memcpy ft_isprint ft_putnbr_fd ft_putendl_fd \
	   ft_putstr_fd ft_putchar_fd ft_strjoin ft_strmapi ft_substr ft_itoa \
	   ft_strtrim ft_split ft_striteri
BFILES= ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
	   ft_lstdelone ft_lstclear ft_lstiter ft_lstmap
OBJS=$(FILES:=.o)
BOBJ=$(BFILES:=.o)

.PHONY: all clean fclean bonus re

all: $(NAME)

bonus: all $(BOBJ)
	ar rcs $(NAME) $(BOBJ)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: %.c libft.h
	$(CC) -c $(FLAGS)  $< -o $@

clean:
	rm -f $(OBJS) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
