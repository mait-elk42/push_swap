/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_adv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:41:01 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/07 21:28:33 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	_part2(t_nsx_node **a, t_nsx_node **b)
{
	while (*b)
	{
		while ((*b)->index != list_length(*b)-1)
		{
			if (get_wanted_index(*b, list_length(*b) - 1) <= list_length(*b) / 2)
				_nsx_instr_rb(b);
			else
				_nsx_instr_rrb(b);
		}
		_nsx_instr_pa(a, b);
	}
}

void	_nsx_sort_adv(t_nsx_node **a, t_nsx_node **b)
{
	int	stack_b_len;
	int offset;

	stack_b_len = 0;
	offset = 16;
	if (list_length(*a) >= 500)
		offset = 32;
	_list_indexing(*a);
	while (*a)
	{
		if ((*a)->index <= stack_b_len)
		{
			_nsx_instr_pb(a, b);
			stack_b_len++;
		} else if ((*a)->index <= offset + stack_b_len)
		{
			_nsx_instr_pb(a, b);
			_nsx_instr_rb(b);
			stack_b_len++;
		}else
			_nsx_instr_ra(a);
	}
	_part2(a, b);
}
