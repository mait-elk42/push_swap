/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_adv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:41:01 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/04 20:00:04 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	lllen(t_nsx_node *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

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

int	where_biggest(t_nsx_node *head)
{
	int	i;
	int	len;

	i = 0;
	len = lllen(head)-1;
	while (head)
	{
		if (head->index == len)
			break ;
		i++;
		head = head->next;
	}
	return (i);
}

void	_part2(t_nsx_node **a, t_nsx_node **b)
{
	int	index;
	int	len;

	_nsx_sort_3(a);
	while ((*b))
	{
		index = where_biggest(*b);
		len = lllen(*b) - 1;
		while ((*b)->index != lllen(*b) - 1)
		{
			if (index >= len / 2)
				_nsx_instr_rrb(b);
			else
				_nsx_instr_rb(b);
		}
		_nsx_instr_pa(a, b);
	}
}

int	bestmv_is_up(t_nsx_node *a, int max)
{
	int	i;
	int	len;
	int	from_start;
	int	from_end;

	i = -1;
	from_start = -1;
	from_end = -1;
	len = lllen(a);
	while (a && i < len/2)
	{
		if (a->index < max && from_start < 0)
			from_start = i;
		i++;
		a = a->next;
	}
	while (a && i < len)
	{
		if (a->index < max)
			from_end = i;
		i++;
		a = a->next;
	}
	if (from_end == -1)
		from_end = len;
	if (from_start == -1)
		from_start = 0;
	// ft_printf("<s%d e%d>\n", from_start, from_end);
	return (from_start < len-from_end + 1);
}

void	_nsx_sort_adv(t_nsx_node **a, t_nsx_node **b)
{
	int	rotateable;
	int	max;
	int best_move_isup;

	index_mylist(*a);
	while (lllen(*a) > 3)
	{
		max = lllen(*a) / 3 + lllen(*b);
		rotateable = lllen(*a) / 6 + lllen(*b);
		best_move_isup = bestmv_is_up(*a, max);
		while (lllen(*b) < max)
		if ((*a)->index < max)
		{
			_nsx_instr_pb(a, b);
			if ((*b)->index < rotateable)
				_nsx_instr_rb(b);
		}
		else
		{
			if (best_move_isup)
				_nsx_instr_rra(a);
			else
				_nsx_instr_ra(a);
				
		}
	}
	_part2(a, b);
}
