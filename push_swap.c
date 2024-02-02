/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:08:30 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/02 12:53:14 by mait-elk         ###   ########.fr       */
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

// int	lllen(t_nsx_node *a)
// {
// 	int	i;
// 	i = 0;
// 	while (a)
// 	{
// 		i++;
// 		a = a->next;
// 	}
// 	return (i);
// }

// int _head_isnot_minwhere(t_nsx_node *a)
// {
// 	int	min;
// 	int len;
// 	int	i;
// 	int c;
// 	min = a->num;
// 	len = lllen(a);
// 	a = a->next;
// 	i = 0;
// 	c = 0;
// 	if (a == NULL)
// 		return (1);
// 	while (a && i <= len/2)
// 	{
// 		if (a->num < min)
// 		{
// 			c = 1;
// 			min = a->num;
// 		}
// 		a = a->next;
// 		i++;
// 	}
// 	while (a && i <= len)
// 	{
// 		if (a->num < min)
// 		{
// 			c = 2;
// 			min = a->num;
// 		}
// 		a = a->next;
// 		i++;
// 	}
// 	return (c);
// }

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
	// OLD 
	// _put_ab(a, b);
	// while (_is_not_sorted(a))
	// {
	// 	int r = _head_isnot_minwhere(a);
	// 	while (r)
	// 	{
	// 		if (r == 1)
	// 			_nsx_instr_ra(&a, &b);
	// 		if (r == 2)
	// 			_nsx_instr_rra(&a, &b);
	// 		r = _head_isnot_minwhere(a);
	// 		// _put_ab(a, b);
	// 	}
	// 	_nsx_instr_pb(&a, &b);
	// 	// _put_ab(a, b);
	// }
	// while (b)
	// 	_nsx_instr_pa(&a, &b);
	// _put_ab(a, b);
	// _nsx_exit_msg("Great ! Let's Sort Numbers!!!");
	if (list_length == 2)
		_nsx_sort_2(&a, &b);
	else if (list_length == 3)
		_nsx_sort_3(&a, &b);
	else if (list_length == 4)
		_nsx_sort_4(&a, &b);
	// else if (list_length == 5)
		// _nsx_sort_5(&a, &b);
	else
		_nsx_sort_adv(&a, &b);
}
