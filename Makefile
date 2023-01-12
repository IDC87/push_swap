# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 08:31:19 by ivda-cru          #+#    #+#              #
#    Updated: 2023/01/12 08:57:14 by ivda-cru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS = -c -Wall -Wextra -Werror 

NAME = push_swap

OBJS=$(patsubst %.c,%.o,$(wildcard *.c))

LIBDIR=./libft

LIBS=./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	${MAKE} -C libft
	$(CC) $(OBJS) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	${MAKE} clean -C libft
	rm -rf $(OBJS) 

fclean: clean
		${MAKE} fclean -C libft
		rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
	
