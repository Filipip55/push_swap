# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icoman <icoman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 16:43:31 by icoman            #+#    #+#              #
#    Updated: 2026/04/02 14:10:05 by icoman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

# File condivisi da entrambi i programmi
SRCS_COMMON = reverse_rotate.c sorting.c stack_a_utils.c stack_utils.c \
              error_management.c push.c rotate.c sorting_utils.c \
              stack_b_utils.c swap.c
OBJS_COMMON = $(SRCS_COMMON:.c=.o)

# File specifico per il mandatory
SRCS_MAN    = main.c
OBJS_MAN    = $(SRCS_MAN:.c=.o)

# File specifico per il bonus
SRCS_BONUS  = checker.c
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_COMMON) $(OBJS_MAN)
	$(CC) $(CFLAGS) $(OBJS_COMMON) $(OBJS_MAN) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(OBJS_COMMON) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_COMMON) $(OBJS_BONUS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_COMMON) $(OBJS_MAN) $(OBJS_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus