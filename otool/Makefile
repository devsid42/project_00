# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 15:08:30 by avasseur          #+#    #+#              #
#    Updated: 2017/03/06 11:42:08 by xubu             ###   ########.fr        #
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

NAME = ft_otool

FAT_OPT = -arch i386 -arch x86_64

X32 = -m32

CC = gcc

HDR = -I inc/ -I ../libft/

DIR = src/

LFT = -L ../libft -lft

SRC = $(DIR)main.c\
	  $(DIR)option.c\
	  $(DIR)init_env.c\
	  $(DIR)usage.c\
	  $(DIR)map.c\
	  $(DIR)tool.c\
	  $(DIR)put.c\
	  $(DIR)handle_fat.c\
	  $(DIR)handle_archive.c\
	  $(DIR)handle_32_64.c

CCFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LFT)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@ $(HDR)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OBJ)

re: fclean all
