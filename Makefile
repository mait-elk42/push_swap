# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 15:38:27 by mait-elk          #+#    #+#              #
#    Updated: 2024/02/11 12:00:44 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Werror -Wextra
HPATH= include
UTILS= utils/args_checker.c utils/utils_.c \
	utils/list.c utils/instractions/instr01.c utils/instractions/instr02.c \
	utils/instractions/instr03.c utils/sorting_lite.c utils/sorting_adv.c \
	utils/list_controller.c
O_UTILS= $(UTILS:.c=.o)
UTILS_BONUS= utils_bonus/args_checker_bonus.c utils_bonus/utils__bonus.c \
	utils_bonus/list_bonus.c utils_bonus/instractions/instr01_bonus.c utils_bonus/instractions/instr02_bonus.c \
	utils_bonus/instractions/instr03_bonus.c utils_bonus/list_controller_bonus.c
O_UTILS_BONUS= $(UTILS_BONUS:.c=.o)
LIBFT_SRCS= libft_advanced/ft_atoi.c \
			libft_advanced/ft_itoa.c \
			libft_advanced/ft_prtf_int.c \
			libft_advanced/ft_putnbr_fd.c \
			libft_advanced/ft_strlcpy.c \
			libft_advanced/ft_tolower.c \
			libft_advanced/ft_bzero.c \
			libft_advanced/ft_prtf_pointer.c \
			libft_advanced/ft_putstr_fd.c \
			libft_advanced/ft_strlen.c \
			libft_advanced/ft_toupper.c \
			libft_advanced/ft_calloc.c \
			libft_advanced/ft_memchr.c \
			libft_advanced/ft_prtf_str.c \
			libft_advanced/ft_split.c \
			libft_advanced/ft_strmapi.c \
			libft_advanced/get_next_line.c \
			libft_advanced/ft_isalnum.c \
			libft_advanced/ft_memcmp.c \
			libft_advanced/ft_prtf_uint.c \
			libft_advanced/ft_strchr.c \
			libft_advanced/ft_strncmp.c \
			libft_advanced/get_next_line_utils.c \
			libft_advanced/ft_isalpha.c \
			libft_advanced/ft_memcpy.c \
			libft_advanced/ft_prtf_uinthex.c \
			libft_advanced/ft_strdup.c \
			libft_advanced/ft_strnstr.c \
			libft_advanced/ft_isascii.c \
			libft_advanced/ft_memmove.c \
			libft_advanced/ft_putbits.c \
			libft_advanced/ft_striteri.c \
			libft_advanced/ft_strrchr.c \
			libft_advanced/ft_isdigit.c \
			libft_advanced/ft_memset.c \
			libft_advanced/ft_putchar_fd.c \
			libft_advanced/ft_strjoin.c \
			libft_advanced/ft_strtrim.c \
			libft_advanced/ft_isprint.c \
			libft_advanced/ft_printf.c \
			libft_advanced/ft_putendl_fd.c \
			libft_advanced/ft_strlcat.c \
			libft_advanced/ft_substr.c

LIBFT=libft_advanced/libft.a
PWDLIBFT=libft_advanced
CC= cc
NAME= push_swap
BONUS= checker

all: $(NAME)

$(NAME): $(LIBFT) $(O_UTILS) push_swap.o
	$(CC) push_swap.o $(LIBFT) $(O_UTILS) -o $(NAME)

push_swap.o: push_swap.c $(HPATH)/push_swap.h
	$(CC) $(CFLAGS) -c push_swap.c -o push_swap.o -I $(HPATH)

utils/%.o: utils/%.c $(HPATH)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HPATH)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(O_UTILS_BONUS) push_swap_bonus.o
	$(CC) push_swap_bonus.o $(LIBFT) $(O_UTILS_BONUS) -o $(BONUS)

push_swap_bonus.o: push_swap_bonus.c $(HPATH)/push_swap_bonus.h
	$(CC) $(CFLAGS) -c push_swap_bonus.c -o push_swap_bonus.o -I $(HPATH)

utils_bonus/%.o: utils_bonus/%.c $(HPATH)/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HPATH)

$(LIBFT): libft_advanced/libft.h $(LIBFT_SRCS)
	make -C $(PWDLIBFT)

clean:
	make -C $(PWDLIBFT) clean
	rm -f $(O_UTILS) push_swap.o $(O_UTILS_BONUS) push_swap_bonus.o

fclean: clean
	make -C $(PWDLIBFT) fclean
	rm -f $(NAME) $(BONUS)

re: fclean all