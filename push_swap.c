/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:08:30 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/25 16:37:19 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	_put_ab(t_nsx_node *a, t_nsx_node *b)
{
	if (!a && !b)
		return ;
	ft_printf("--------------------------\n");
	while (a)
	{
			ft_printf("[A%d]\t", a->num);
			a = a->next;
		ft_printf("\n");
	}
	ft_printf(" A\t B\n");
	ft_printf("--------------------------\n");


}

int	main(int ac, char **av)
{
	t_nsx_node	*a;
	t_nsx_node	*b;
	char		**numbers;

	a = NULL;
	b = NULL;
	 numbers = _nsx_get_list(ac, av);
	// _nsx_args_checker(ac, av);
	// _nsx_num_checker(ac, av);
	// a = _nsx_2darr2list(numbers);
	// _put_ab(a, b);
	// _nsx_instr_pb(&a, &b);
	// _nsx_instr_pb(&a, &b);
	// _put_ab(a, b);
	// _nsx_instr_pb(&a, &b);
	// // _nsx_instr_sa(a);
	// // _nsx_instr_pb(&a, &b);
	// _nsx_exit("Great ! Let's Sort Numbers!!!", 0, 0);
	_nsx_lstadd_atbegin(&a, _nsx_lstnew_node(3));
	_nsx_lstadd_atbegin(&a, _nsx_lstnew_node(2));
	_nsx_lstadd_atbegin(&a, _nsx_lstnew_node(1));
	// _put_ab(a, b);
	_nsx_instr_pb(&a, &b);
	// _put_ab(a, b);
	_nsx_instr_pb(&a, &b);
	_put_ab(a, b);
	// printf("%d\n", a->num);
	// printf("%d\n", b->num);
	// printf("%d\n", b->next->num);
	// printf("%d\n", a->next->num);
}
