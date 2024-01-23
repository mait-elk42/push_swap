/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:08:30 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/24 00:43:41 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_putitemrev(t_nsx_node *head)
{
	if (!head)
		return ;
	_putitemrev(head->next);
	ft_printf("[%d]\n", head->num);
}

void	_putitem(t_nsx_node *head)
{
	while (head)
	{
		ft_printf("[%d]\n", head->num);
		head = head->next;
	}
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
	ft_printf("ORIGIN\n\n");
	a = _nsx_2darr2list(numbers);
	_nsx_instr_pb(&a, &b);
	_nsx_instr_pb(&a, &b);
	ft_printf(" A\n");
	_putitem(a);
	ft_printf("\n B\n");
	_putitemrev(b);
	_nsx_exit("Great ! Let's Sort Numbers!!!", 0, 0);
	return (0);
}
