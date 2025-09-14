# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nobu <nobu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 01:36:01 by nobu              #+#    #+#              #
#    Updated: 2025/08/30 06:14:14 by nobu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.. -I../includes
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re