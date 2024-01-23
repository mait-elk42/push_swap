/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:08:30 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/23 13:22:53 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_nsx_node	*A;
	t_nsx_node	*B;

	A = NULL;
	B = NULL;
	_nsx_args_checker(ac, av);
	_nsx_num_checker(ac, av);
	_nsx_exit("Great ! Let's Sort Your Shit!", 0, 0);
	return (0);
}

