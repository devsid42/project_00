# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 15:08:30 by avasseur          #+#    #+#              #
#    Updated: 2017/03/06 11:39:38 by xubu             ###   ########.fr        #
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

HDR = ../inc/

SRC = $(shell ls | grep "\.c")

CCFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all:
	make -C libft/
	make -C nm/
	make -C otool/

clean:
	make -C libft/ clean 
	make -C nm/ clean
	make -C otool/ clean

fclean: clean
	make -C libft/ fclean
	make -C nm/ fclean
	make -C otool/ fclean

re: fclean all
