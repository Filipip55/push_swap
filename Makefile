# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icoman <icoman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 16:43:31 by icoman            #+#    #+#              #
#    Updated: 2026/03/28 17:29:24 by icoman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap.a
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f
SRCS        = reverse_rotate.c sorting.c stack_a_utils.c stack_utils.c error_management.c\
				main.c push.c rotate.c sorting_utils.c stack_b_utils.c swap.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re