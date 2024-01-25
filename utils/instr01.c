/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:57:35 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/25 16:32:57 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	_nsx_instr_sa(t_nsx_node *a)
{
	int tmp;

	if (!a || !a->next)
		return ;
	tmp = a->next->num;
	a->next->num = a->num;
	a->num = tmp;
	ft_printf("sa\n");
}

void	_nsx_instr_sb(t_nsx_node *b)
{
	int tmp;

	if (!b || !b->next)
		return ;
	tmp = b->next->num;
	b->next->num = b->num;
	b->num = tmp;
	ft_printf("sb\n");
}

void	_nsx_instr_ss(t_nsx_node *a, t_nsx_node *b)
{
	_nsx_instr_sa(a);
	_nsx_instr_sb(b);
	ft_printf("ss\n");
}

void	_nsx_instr_pb(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node *first;
	t_nsx_node *sec;

	first = *a;
	sec = (*a)->next;
	first->next = NULL;
	(*a) = sec;
	_nsx_lstadd_atbegin(b, first);
	// (*a) = (*a)->next;
	ft_printf("pb\n");
}