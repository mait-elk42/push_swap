/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_adv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:41:01 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/07 20:01:00 by mait-elk         ###   ########.fr       */
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
	int	blen;
	int what;

	blen = 0;
	what = 16;
	if (list_length(*a) >= 500)
		what = 32;
	_list_indexing(*a);
	while (*a)
	{
		if ((*a)->index <= blen)
		{
			_nsx_instr_pb(a, b);
			blen++;
		} else if ((*a)->index <= blen + what)
		{
			_nsx_instr_pb(a, b);
			_nsx_instr_rb(b);
			blen++;
		}else
			_nsx_instr_ra(a);
	}
	_part2(a, b);
}
