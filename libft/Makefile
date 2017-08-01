# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 15:08:30 by avasseur          #+#    #+#              #
#    Updated: 2015/06/09 15:55:01 by avasseur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREY = "\033[30m"
RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
BLUE = "\033[34m"
PURPLE = "\033[35m"
CYAN = "\033[36m"
WHITE = "\033[37m"
ENDCOLOR = "\033[0m"

FAT_OPT = -arch i386 -arch x86_64

X32 = -m32

NAME = libft.a

CC = gcc

HDR = ../inc/

SRC = $(shell ls | grep "\.c")

CCFLAGS = -Wall -Werror -Wextra


OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN)"Making Done LFT"$(ENDCOLOR)

%.o: %.c
	@$(CC) $(CCFLAGS) -c $< -o $@ -I $(HDR)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
