# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:58:04 by jvarila           #+#    #+#              #
#    Updated: 2024/11/12 11:26:51 by jvarila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HF = libft.h
AR = ar -crs

SRC =	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	\
	ft_isprint.c	ft_strlen.c	ft_memset.c	ft_bzero.c	\
	ft_memcpy.c	ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	\
	ft_toupper.c	ft_tolower.c	ft_strchr.c	ft_strrchr.c	\
	ft_strncmp.c	ft_memchr.c	ft_memcmp.c	ft_strnstr.c	\
	ft_atoi.c	ft_calloc.c	ft_strdup.c	ft_substr.c	\
	ft_strjoin.c	ft_strtrim.c	ft_split.c	ft_itoa.c	\
	ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	\
	ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr.c	ft_putchar.c	\
	ft_putendl.c	ft_putnbr.c	ft_putnbr_base.c

OBJ = $(SRC:.c=.o)

BONUSSRC =	ft_lstnew_bonus.c	\
		ft_lstadd_front_bonus.c	\
		ft_lstsize_bonus.c	\
		ft_lstlast_bonus.c	\
		ft_lstadd_back_bonus.c	\
		ft_lstdelone_bonus.c	\
		ft_lstclear_bonus.c	\
		ft_lstiter_bonus.c	\
		ft_lstmap_bonus.c

BONUSOBJ = $(BONUSSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HF)
	$(AR) $(NAME) $(OBJ)

bonus: .bonus

.bonus: $(OBJ) $(BONUSOBJ) $(HF)
	$(AR) $(NAME) $(OBJ) $(BONUSOBJ)
	@touch .bonus

clean:
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus
