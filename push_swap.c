/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:38:04 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/04 18:46:03 by mait-elk         ###   ########.fr       */
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
		ft_printf("[%d] <%d>\n", a->num, a->index);
		a = a->next;
	}
	ft_printf(" B\n");
	while (b)
	{
		ft_printf("[%d] <%d>\n", b->num, b->index);
		b = b->next;
	}
	ft_printf("\n--------------------------\n");
}

int	_is_not_sorted(t_nsx_node *a_head)
{
	if (!a_head)
		return (-1);
	while (a_head->next)
	{
		if (a_head->num > a_head->next->num)
			return (1);
		a_head = a_head->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_nsx_node	*a;
	t_nsx_node	*b;
	char		**numbers;
	size_t		list_length;

	a = NULL;
	b = NULL;
	list_length = 0;
	numbers = _nsx_get_list(ac, av);
	_nsx_args_checker(ac, av);
	_nsx_num_checker(ac, av);
	while (numbers[list_length])
		list_length++;
	a = _nsx_2darr2list(numbers);
	if (list_length == 2)
		_nsx_sort_2(&a);
	else if (list_length == 3)
		_nsx_sort_3(&a);
	else if (list_length == 4)
		_nsx_sort_4(&a, &b);
	else
		_nsx_sort_adv(&a, &b);
}
