/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_adv_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:41:01 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/07 04:41:57 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	index_mylist(t_nsx_node *head)
{
	t_nsx_node	*save_head;
	t_nsx_node	*tmp;

	save_head = head;
	while (head)
	{
		tmp = save_head;
		while (tmp)
		{
			if (head->num > tmp->num)
				head->index++;
			tmp = tmp->next;
		}
		head = head->next;
	}
}

void	_part2(t_nsx_node **a, t_nsx_node **b)
{
	int	yes;

	yes = 0;
	_nsx_sort_3(a);
	while (*b || !_is_sorted(*a))
		if ((*b) && (*b)->index == (*a)->index - 1)
			_nsx_instr_pa(a, b);
	else if ((*b) && _get_last_node(*b)->index == (*a)->index - 1)
		(_nsx_instr_rrb(b), _nsx_instr_pa(a, b));
	else if (yes && _get_last_node(*a)->index == (*a)->index - 1)
		(_nsx_instr_rra(a), yes--);
	else if (yes == 0)
		(_nsx_instr_pa(a, b), _nsx_instr_ra(a), yes++);
	else if ((*b) && yes && _get_last_node(*a)->index < (*b)->index)
		(_nsx_instr_pa(a, b), _nsx_instr_ra(a), yes++);
	else if ((*b) && yes
		&& _get_last_node(*a)->index < _get_last_node(*b)->index)
		(_nsx_instr_rrb(b), _nsx_instr_pa(a, b), _nsx_instr_ra(a), yes++);
	else
	{
		if (get_wanted_index(*b, (*a)->index - 1) < list_length(*b) / 2)
			_nsx_instr_rb(b);
		else
			_nsx_instr_rrb(b);
	}
}

void	_nsx_sort_adv(t_nsx_node **a, t_nsx_node **b)
{
	int	rotateable;
	int	max;

	index_mylist(*a);
	while (list_length(*a) > 3)
	{
		max = list_length(*a) / 3 + list_length(*b);
		rotateable = list_length(*a) / 6 + list_length(*b);
		while (list_length(*b) < max)
		{
			if ((*a)->index < max)
			{
				_nsx_instr_pb(a, b);
				if ((*a)->index > max && (*b)->index <= rotateable)
					_nsx_instr_rr(a, b);
				else if ((*b)->index < rotateable)
					_nsx_instr_rb(b);
			}
			else
				_nsx_instr_ra(a);
		}
	}
	_part2(a, b);
}
