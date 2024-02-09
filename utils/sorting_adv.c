/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_adv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:41:01 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/09 09:46:07 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	_part2(t_nsx_node **a, t_nsx_node **b)
{
	while (*b)
	{
		while ((*b)->index != list_length(*b) - 1)
		{
			if (get_index(*b, list_length(*b) - 1) <= list_length(*b) / 2)
				_nsx_instr_rb(b);
			else
				_nsx_instr_rrb(b);
		}
		_nsx_instr_pa(a, b);
	}
}

void	_nsx_sort_adv(t_nsx_node **a, t_nsx_node **b)
{
	int	offset;

	offset = 16;
	if (list_length(*a) >= 300)
		offset = 32;
	_list_indexing(*a);
	while (*a)
	{
		if ((*a)->index <= list_length(*b))
			_nsx_instr_pb(a, b);
		else if ((*a)->index <= offset + list_length(*b))
			(_nsx_instr_pb(a, b), _nsx_instr_rb(b));
		else
			_nsx_instr_ra(a);
	}
	_part2(a, b);
}
