# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 15:38:27 by mait-elk          #+#    #+#              #
#    Updated: 2024/02/07 06:45:12 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Werror -Wextra
HPATH= include
UTILS= utils/args_checker.c utils/logger.c utils/free_all.c utils/reader.c \
	utils/list.c utils/protect.c utils/instractions/instr01.c utils/instractions/instr02.c \
	utils/instractions/instr03.c utils/sorting_lite.c utils/sorting_adv.c \
	utils/list_controller.c
B_UTILS= utils_bonus/args_checker_bonus.c utils_bonus/logger_bonus.c utils_bonus/free_all_bonus.c utils_bonus/reader_bonus.c \
	utils_bonus/list_bonus.c utils_bonus/protect_bonus.c utils_bonus/instractions/instr01_bonus.c utils_bonus/instractions/instr02_bonus.c \
	utils_bonus/instractions/instr03_bonus.c utils_bonus/sorting_lite_bonus.c utils_bonus/sorting_adv_bonus.c \
	utils_bonus/list_controller_bonus.c
O_UTILS= $(UTILS:.c=.o)
B_O_UTILS= $(B_UTILS:.c=.o)
LIBFT=libft_advanced/libft.a
PWDLIBFT=libft_advanced
CC= cc
BONUS= checker
NAME= push_swap

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(LIBFT) $(O_UTILS) push_swap.o
	$(CC) push_swap.o $(LIBFT) $(O_UTILS) -o $(NAME)

$(BONUS): $(LIBFT) $(B_O_UTILS) push_swap_bonus.o
	$(CC) push_swap_bonus.o $(LIBFT) $(B_O_UTILS) -o $(BONUS)

push_swap.o: push_swap.c $(HPATH)/push_swap.h
	$(CC) $(CFLAGS) -c push_swap.c -o push_swap.o -I $(HPATH)

push_swap_bonus.o: push_swap_bonus.c $(HPATH)/push_swap_bonus.h
	$(CC) $(CFLAGS) -c push_swap_bonus.c -o push_swap_bonus.o -I $(HPATH)

utils/%.o: utils/%.c $(HPATH)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HPATH)

utils_bonus/%.o: utils_bonus/%.c $(HPATH)/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HPATH)
	
$(LIBFT):
	make -C $(PWDLIBFT)

clean:
	make -C $(PWDLIBFT) clean
	rm -f $(O_UTILS) $(B_O_UTILS) push_swap.o push_swap_bonus.o

fclean: clean
	make -C $(PWDLIBFT) fclean
	rm -f $(NAME) $(BONUS)

re: fclean all