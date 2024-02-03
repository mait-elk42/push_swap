/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_adv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:41:01 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/03 20:31:36 by mait-elk         ###   ########.fr       */
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
	int i = 0;
	int len = lllen(head)-1;
	while (head)
	{
		if (head->index == len)
			break;
		i++;
		head = head->next;
	}
	return (i);
}

void	_nsx_sort_adv(t_nsx_node **a, t_nsx_node **b)
{
	int rotateable;
	int max;

	index_mylist(*a);
	while (lllen(*a) > 3)
	{
		max = lllen(*a) / 3 + lllen(*b);
		rotateable = lllen(*a) / 6 + lllen(*b);
		while (lllen(*b) < max)
		{
			if ((*a)->index < max)
			{
				_nsx_instr_pb(a, b);
				if ((*b)->index < rotateable)
					_nsx_instr_rb(a, b);
			}
			else
				_nsx_instr_ra(a, b);
		}
	}
	_nsx_sort_3(a, b);
	while ((*b))
	{
		int index = where_biggest(*b);
		int len = lllen(*b) - 1;
		while ((*b)->index != lllen(*b) - 1)
		{
			if (index >= len / 2)
				_nsx_instr_rrb(a, b);
			else
				_nsx_instr_rb(a, b);
		}
		_nsx_instr_pa(a, b);
	}
}
