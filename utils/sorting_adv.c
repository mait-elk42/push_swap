/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_adv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:41:01 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/02 23:54:38 by mait-elk         ###   ########.fr       */
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

void	_nsx_sort_adv(t_nsx_node **a, t_nsx_node **b)
{
	int pivo1;
	int pivo2;

	pivo2 = 0;
	index_mylist(*a);
	while (lllen(*a) > 3)
	{
		pivo1 = lllen(*a) / 6 + pivo2;
		pivo2 += lllen(*a) / 3;
		// ft_printf("[p1 : %d | p2 : %d]\n", pivo1, pivo2);
		// _put_ab(*a, *b);
		while (lllen(*b) < pivo2)
		{
			if ((*a)->index < pivo2)
			{
				_nsx_instr_pb(a, b);
				if ((*b)->index < pivo1)
					_nsx_instr_rb(a, b);
			}
			else
				_nsx_instr_ra(a, b);
		}
	}
	// _nsx_sort_3(a, b);
}
