# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 15:38:27 by mait-elk          #+#    #+#              #
#    Updated: 2024/01/23 11:53:46 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Werror -Wextra
HPATH= include
UTILS= utils/args_checker.c utils/logger.c utils/free_all.c utils/reader.c
O_UTILS= $(UTILS:.c=.o)
LIBFT=libft_advanced/libft.a
PWDLIBFT=libft_advanced
CC= cc
NAME= push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(O_UTILS) push_swap.o
	$(CC) push_swap.o $(LIBFT) $(O_UTILS) -o $(NAME)

push_swap.o: push_swap.c $(HPATH)/push_swap.h
	$(CC) $(CFLAGS) -c push_swap.c -o push_swap.o -I $(HPATH)

utils/%.o: utils/%.c $(HPATH)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HPATH)
	
$(LIBFT):
	make -C $(PWDLIBFT)

clean:
	make -C $(PWDLIBFT) clean
	rm -f $(O_UTILS) push_swap.o

fclean: clean
	make -C $(PWDLIBFT) fclean
	rm -f $(NAME)

re: fclean all