/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:57:35 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/29 11:44:01 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	_nsx_instr_ra(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node	*node;

	node = *a;
	(*a) = node->next;
	node->next = 0;
	_nsx_lstadd_atlast(a, node);
	ft_printf("ra\n");
}

void	_nsx_instr_rb(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node	*node;

	node = *b;
	(*b) = node->next;
	node->next = 0;
	_nsx_lstadd_atlast(b, node);
	ft_printf("rb\n");
}

void	_nsx_instr_rr(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node	*node;

	node = *a;
	(*a) = node->next;
	node->next = 0;
	_nsx_lstadd_atlast(a, node);
	node = *b;
	(*b) = node->next;
	node->next = 0;
	_nsx_lstadd_atlast(b, node);
	ft_printf("rr\n");
}

void	_nsx_instr_rra(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node	*node;

	node = *a;
	while (node->next->next)
		node = node->next;
	_nsx_lstadd_atbegin(a, node->next);
	*a = node->next;
	node->next = 0;
	ft_printf("ra\n");
}

void	_nsx_instr_rrb(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node	*node;

	node = *b;
	while (node->next->next)
		node = node->next;
	_nsx_lstadd_atbegin(b, node->next);
	*b = node->next;
	node->next = 0;
	ft_printf("rb\n");
}
