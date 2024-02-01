/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_adv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:41:01 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/01 16:16:08 by mait-elk         ###   ########.fr       */
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

static int _head_isnot_biggerwhere(t_nsx_node *head)
{
	int	max;
	int len;
	int	i;
	int c;

	max = head->num;
	len = lllen(head);
	i = 0;
	c = 0;
	if (head == NULL || head->next == NULL)
		return (0);
	head = head->next;
	while (head && i <= len/2)
	{
		if (head->num > max)
		{
			c = 1;
			max = head->num;
		}
		head = head->next;
		i++;
	}
	while (head && i <= len)
	{
		if (head->num > max)
		{
			c = 2;
			max = head->num;
		}
		head = head->next;
		i++;
	}
	return (c);
}

void	_nsx_sort_adv(t_nsx_node **a, t_nsx_node **b)
{
	int		head_is_bigger;
	while (*a)
	{
		_nsx_instr_pb(a, b);
		if ((*b) && (*b)->next && (*b)->next->num > (*b)->num)
			_nsx_instr_rb(a, b);
	}
	while ((*b))
	{
		int bigger = _head_isnot_biggerwhere(*b);
		if (bigger == 1)
			_nsx_instr_rb(a, b);
		if (bigger == 2)
			_nsx_instr_rrb(a, b);
		if (bigger == 0)
			_nsx_instr_pa(a, b);
	}
}