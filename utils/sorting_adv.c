/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_adv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:41:01 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/01 14:27:21 by mait-elk         ###   ########.fr       */
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
	int	min;
	int len;
	int	i;
	int c;

	min = head->num;
	len = lllen(head);
	head = head->next;
	i = 0;
	c = 0;
	if (head == NULL)
		return (1);
	while (head && i <= len/2)
	{
		if (head->num < min)
		{
			c = 1;
			min = head->num;
		}
		head = head->next;
		i++;
	}
	while (head && i <= len)
	{
		if (head->num < min)
		{
			c = 2;
			min = head->num;
		}
		head = head->next;
		i++;
	}
	return (c);
}

void	_nsx_sort_adv(t_nsx_node **a, t_nsx_node **b)
{
	int		head_is_bigger;
	(void)a;
	(void)b;
	while (*a)
	{
		_nsx_instr_pb(a, b);
		if ((*b) && (*b)->next && (*b)->next->num > (*b)->num)
			_nsx_instr_rb(a, b);
	}
	// while ((*b))
	// {
	// 	if (_head_isnot_biggerwhere(*b) == 1)
	// 		_nsx_instr_rb(a, b);
	// 	else
	// 	if (_head_isnot_biggerwhere(*b) == 2)
	// 		_nsx_instr_rrb(a, b);
	// 	else
	// 	if (_head_isnot_biggerwhere(*b) == 0)
	// 		_nsx_instr_pa(a, b);
	// }
	ft_printf("%d\n", _head_isnot_biggerwhere(*b));
	_put_ab(*a, *b);
}