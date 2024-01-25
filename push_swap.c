/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:08:30 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/25 18:43:58 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	_put_ab(t_nsx_node *a, t_nsx_node *b)
{
	if (!a && !b)
		return ;
	ft_printf("--------------------------\n");
	ft_printf(" A\n");
	while (a)
	{
		ft_printf("[%d]\n", a->num);
		a = a->next;
	}
	ft_printf(" B\n");
	while (b)
	{
		ft_printf("[%d]\n", b->num);
		b = b->next;
	}
	ft_printf("\n--------------------------\n");
}

int	main(int ac, char **av)
{
	t_nsx_node	*a;
	t_nsx_node	*b;
	char		**numbers;

	a = NULL;
	b = NULL;
	 numbers = _nsx_get_list(ac, av);
	_nsx_args_checker(ac, av);
	_nsx_num_checker(ac, av);
	a = _nsx_2darr2list(numbers);
	_put_ab(a, b);
	_nsx_exit("Great ! Let's Sort Numbers!!!", 0, 0);
}
