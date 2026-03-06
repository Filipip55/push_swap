# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icoman <icoman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/06 16:33:53 by icoman            #+#    #+#              #
#    Updated: 2026/03/06 16:33:53 by icoman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
LIBFT_DIR   = ../libft
LIBFT       = $(LIBFT_DIR)/libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
SRCS        = main.c init_stack.c stack_utils.c swap.c push.c rotate.c \
              rev_rotate.c sort_three.c sort_cost.c sort_exec.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
