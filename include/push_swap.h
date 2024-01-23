/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:44:28 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/23 12:34:29 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "../libft_advanced/libft.h"

typedef struct s_nsx_node
{
	struct s_nsx_node	*prev;
	int					number;
	struct s_nsx_node	*next;
} t_nsx_node;

void	_nsx_args_checker(int ac, char **av);
void	_nsx_num_checker(int ac, char **av);
void	_nsx_exit(char *msg, int status, char type);
void	_nsx_free_2darray(char **arr);

char	**_nsx_get_list(int ac, char **av);
#endif