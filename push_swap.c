/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:08:30 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/23 16:53:06 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_nsx_node	*a;
	t_nsx_node	*b;

	a = NULL;
	b = NULL;
	_nsx_args_checker(ac, av);
	_nsx_num_checker(ac, av);
	_nsx_exit("Great ! Let's Sort Numbers Genteeel man Joeee!!!", 0, 0);
	return (0);
}
