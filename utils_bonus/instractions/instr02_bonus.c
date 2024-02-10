/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr02_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:57:35 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/10 12:40:44 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	_nsx_instr_ra(t_nsx_node **a)
{
	t_nsx_node	*node;

	if (!a || !*a || !(*a)->next)
		return ;
	node = *a;
	(*a) = node->next;
	node->next = 0;
	_nsx_lstadd_atlast(a, node);
}

void	_nsx_instr_rb(t_nsx_node **b)
{
	t_nsx_node	*node;

	if (!b || !*b || !(*b)->next)
		return ;
	node = *b;
	(*b) = node->next;
	node->next = 0;
	_nsx_lstadd_atlast(b, node);
}

void	_nsx_instr_rr(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node	*node;

	if (!a || !b || !*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	node = *a;
	(*a) = node->next;
	node->next = 0;
	_nsx_lstadd_atlast(a, node);
	node = *b;
	(*b) = node->next;
	node->next = 0;
	_nsx_lstadd_atlast(b, node);
}

void	_nsx_instr_rra(t_nsx_node **a)
{
	t_nsx_node	*node;

	if (!a || !*a || !(*a)->next)
		return ;
	node = *a;
	while (node->next->next)
		node = node->next;
	_nsx_lstadd_atbegin(a, node->next);
	*a = node->next;
	node->next = 0;
}

void	_nsx_instr_rrb(t_nsx_node **b)
{
	t_nsx_node	*node;

	if (!b || !*b || !(*b)->next)
		return ;
	node = *b;
	while (node->next->next)
		node = node->next;
	_nsx_lstadd_atbegin(b, node->next);
	*b = node->next;
	node->next = 0;
}
