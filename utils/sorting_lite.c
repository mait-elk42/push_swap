/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_lite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:40:12 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/02 12:28:57 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	_nsx_sort_2(t_nsx_node **a, t_nsx_node **b)
{
	if ((*a)->num > (*a)->next->num)
		_nsx_instr_sa(a);
	_put_ab(*a, *b);
}

void	_nsx_sort_3(t_nsx_node **a, t_nsx_node **b)
{
	if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num)
		_nsx_instr_ra(a, b);
	if ((*a)->next->num > (*a)->num && (*a)->next->num > (*a)->next->next->num)
		_nsx_instr_rra(a, b);
	if ((*a)->num > (*a)->next->num)
		_nsx_instr_sa(a);
	_put_ab(*a, *b);
}

int	_get_min_position(t_nsx_node *head)
{
	t_nsx_node	*tmphead;
	int			i;
	int			j;
	int			ok;

	i = 0;
	while (head)
	{
		j = 0;
		ok = 0;
		tmphead = head->next;
		while (tmphead)
		{
			if (head->num  < tmphead->num)
				ok++;
			j++;
			tmphead = tmphead->next;
		}
		if (ok == j)
			return (i);
		i++;
		head = head->next;
	}
	return (-1);
}

void	_nsx_sort_4(t_nsx_node **a, t_nsx_node **b)
{
	int	min_pos;

	min_pos = _get_min_position(*a);
	if (min_pos == 0)
		_nsx_instr_pb(a, b);
	if (min_pos == 1)
		_nsx_instr_sa(a);
	if (min_pos == 2)
	{
		_nsx_instr_ra(a, b);
		_nsx_instr_ra(a, b);
	}
	if (min_pos == 3)
		_nsx_instr_rra(a, b);
	if (_is_not_sorted(*a))
	{
		_nsx_instr_pb(a, b);
		_nsx_sort_3(a, b);
		_nsx_instr_pa(a, b);
	}
	_put_ab(*a, *b);
}

// void	_nsx_sort_5(t_nsx_node **a, t_nsx_node **b)
// {
// 	int	min_pos;

// 	min_pos = _get_min_position(*a);
// 	if (min_pos == 0)
// 		_nsx_instr_pb(a, b);
// 	if (min_pos == 1)
// 		_nsx_instr_sa(*a);
// 	if (min_pos == 2)
// 	{
// 		_nsx_instr_ra(a, b);
// 		_nsx_instr_ra(a, b);
// 	}
// 	if (min_pos == 3)
// 	{
// 		_nsx_instr_rra(a, b);
// 		_nsx_instr_rra(a, b);
// 	}
// 	if (min_pos == 4)
// 	{
// 		_nsx_instr_rra(a, b);
// 	}
// 	if (_is_not_sorted(*a))
// 	{
// 		_nsx_instr_pb(a, b);
// 		_nsx_sort_4(a, b);
// 		_nsx_instr_pa(a, b);
// 	}
// 	// _put_ab(*a, *b);
// }
