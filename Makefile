# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/27 00:41:53 by werlim            #+#    #+#              #
#    Updated: 2026/10/15 13:27:29 by werlim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

PRINTF_DIR	=	ps_printf
PRINTF		=	$(PRINTF_DIR)/psprintf.a

INCLUDES	=	-I. -I$(PRINTF_DIR)

SRCS	=	push_swap.c op_swap.c op_push.c op_rotate.c op_rev_rotate.c\
			ftps_node_helper.c

OBJS	=	$(SRCS:.c=.o)

all: libs $(NAME)

libs:
	&(MAKE) -C $(PRINTF_DIR)
	
$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all libs clean fclean re