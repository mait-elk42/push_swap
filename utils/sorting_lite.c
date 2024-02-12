/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_lite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:40:12 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/12 10:38:45 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	_nsx_sort_2(t_nsx_node **a)
{
	if ((*a)->num > (*a)->next->num)
		_nsx_instr_sa(a);
}

void	_nsx_sort_3(t_nsx_node **a)
{
	if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num)
		_nsx_instr_ra(a);
	if ((*a)->next->num > (*a)->num && (*a)->next->num > (*a)->next->next->num)
		_nsx_instr_rra(a);
	if ((*a)->num > (*a)->next->num)
		_nsx_instr_sa(a);
}

void	_nsx_sort_4_5(t_nsx_node **a, t_nsx_node **b)
{
	int	chhal;
	int	min_pos;

	chhal = 0;
	_list_indexing(*a);
	while (list_length(*a) != 3)
	{
		min_pos = get_index(*a, list_length(*b));
		while (min_pos != 0)
		{
			if (min_pos > list_length(*a) / 2)
				_nsx_instr_rra(a);
			else
				_nsx_instr_ra(a);
			min_pos = get_index(*a, list_length(*b));
		}
		_nsx_instr_pb(a, b);
		chhal++;
	}
	_nsx_sort_3(a);
	while (chhal--)
		_nsx_instr_pa(a, b);
}
