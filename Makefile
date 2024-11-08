# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:58:04 by jvarila           #+#    #+#              #
#    Updated: 2024/11/07 17:11:44 by jvarila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HF = libft.h
CFILES = 	ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_strlen.c	\
		ft_memset.c	\
		ft_bzero.c	\
		ft_memcpy.c	\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c	\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_strnstr.c	\
		ft_atoi.c	\
		ft_calloc.c	\
		ft_strdup.c	\
		ft_substr.c	\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c	\
		ft_itoa.c	\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(HF) $(OFILES)
	ar rcs $(NAME) $(OFILES)

ft_isalpha.o	: ft_isalpha.c	$(HF)

ft_isdigit.o	: ft_isdigit.c	$(HF)

ft_isalnum.o	: ft_isalnum.c	$(HF)

ft_isascii.o	: ft_isascii.c	$(HF)

ft_isprint.o	: ft_isprint.c	$(HF)

ft_strlen.o	: ft_strlen.c	$(HF)

ft_memset.o	: ft_memset.c	$(HF)

ft_bzero.o	: ft_bzero.c	$(HF)

ft_memcpy.o	: ft_memcpy.c	$(HF)

ft_memmove.o	: ft_memmove.c	$(HF)

ft_strlcpy.o	: ft_strlcpy.c	$(HF)

ft_strlcat.o	: ft_strlcat.c	$(HF)

ft_toupper.o	: ft_toupper.c	$(HF)

ft_tolower.o	: ft_tolower.c	$(HF)

ft_strchr.o	: ft_strchr.c	$(HF)

ft_strrchr.o	: ft_strrchr.c	$(HF)

ft_strncmp.o	: ft_strncmp.c	$(HF)

ft_memchr.o	: ft_memchr.c	$(HF)

ft_memcmp.o	: ft_memcmp.c	$(HF)

ft_strnstr.o	: ft_strnstr.c	$(HF)

ft_atoi.o	: ft_atoi.c	$(HF)

ft_calloc.o	: ft_calloc.c	$(HF)

ft_strdup.o	: ft_strdup.c	$(HF)

ft_substr.o	: ft_substr.c	$(HF)

ft_strjoin.o	: ft_strjoin.c	$(HF)

ft_strtrim.o	: ft_strtrim.c	$(HF)

ft_split.o	: ft_split.c	$(HF)

ft_itoa.o	: ft_itoa.c	$(HF)

ft_strmapi.o	: ft_strmapi.c	$(HF)

ft_striteri.o	: ft_striteri.c	$(HF)

ft_putchar_fd.o	: ft_putchar_fd.c	$(HF)

ft_putstr_fd.o	: ft_putstr_fd.c	$(HF)

ft_putendl_fd.o	: ft_putendl_fd.c	$(HF)

ft_putnbr_fd.o	: ft_putnbr_fd.c	$(HF)

.PHONY: clean fclean re

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean a
