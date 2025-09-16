# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/15 14:59:11 by adavitas          #+#    #+#              #
#    Updated: 2025/09/15 14:59:22 by adavitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CHECK   = checker
PRINTF  = ./ft_printf/libftprintf.a

SRCS_PUSH    = $(wildcard src/push_swap/*.c)
SRCS_UTILS   = $(wildcard utils/*.c)
SRCS_CHECKER = $(wildcard src/checker/*.c)

PUSHSWAP_OBJS := $(SRCS_PUSH:.c=.o)
PUSHSWAP_OBJS_NO_MAIN := $(filter-out src/push_swap/push_swap.o,$(PUSHSWAP_OBJS))
UTILS_OBJS := $(SRCS_UTILS:.c=.o)
CHECK_OBJS := $(SRCS_CHECKER:.c=.o)

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -Iincludes -Ift_printf
RM      = rm -rf

GREEN   = \033[0;32m
RESET   = \033[0m

all: $(NAME) $(CHECK)

$(NAME): $(PUSHSWAP_OBJS) $(UTILS_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(PUSHSWAP_OBJS) $(UTILS_OBJS) $(PRINTF) -o $(NAME) > /dev/null
	@echo -e "${GREEN}[OK] ${NAME} compiled${RESET}"

$(CHECK): $(CHECK_OBJS) $(PUSHSWAP_OBJS_NO_MAIN) $(UTILS_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(CHECK_OBJS) $(PUSHSWAP_OBJS_NO_MAIN) $(UTILS_OBJS) $(PRINTF) -o $(CHECK) > /dev/null
	@echo -e "${GREEN}[OK] ${CHECK} compiled${RESET}"

$(PRINTF):
	@$(MAKE) -C ./ft_printf > /dev/null

clean:
	@$(MAKE) -C ./ft_printf clean > /dev/null
	@$(RM) $(PUSHSWAP_OBJS) $(UTILS_OBJS) $(CHECK_OBJS)
	@echo -e "${GREEN}[OK] Object files removed${RESET}"

fclean: clean
	@$(MAKE) -C ./ft_printf fclean > /dev/null
	@$(RM) $(NAME) $(CHECK)
	@echo -e "${GREEN}[OK] Executables removed${RESET}"

re: fclean all

.PHONY: all clean fclean re


