/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr02_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:57:35 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/09 19:08:02 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	_nsx_instr_ra(t_nsx_node **a)
{
	t_nsx_node	*node;

	if (!a || !*a)
		return ;
	node = *a;
	(*a) = node->next;
	node->next = 0;
	_nsx_lstadd_atlast(a, node);
	ft_printf("ra\n");
}

void	_nsx_instr_rb(t_nsx_node **b)
{
	t_nsx_node	*node;

	if (!b || !*b)
		return ;
	node = *b;
	(*b) = node->next;
	node->next = 0;
	_nsx_lstadd_atlast(b, node);
	ft_printf("rb\n");
}

void	_nsx_instr_rr(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node	*node;

	if (!a || !b || !*a || !*b)
		return ;
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

void	_nsx_instr_rra(t_nsx_node **a)
{
	t_nsx_node	*node;

	if (!a || !*a)
		return ;
	node = *a;
	while (node->next->next)
		node = node->next;
	_nsx_lstadd_atbegin(a, node->next);
	*a = node->next;
	node->next = 0;
	ft_printf("rra\n");
}

void	_nsx_instr_rrb(t_nsx_node **b)
{
	t_nsx_node	*node;

	if (!b || !*b)
		return ;
	node = *b;
	while (node->next->next)
		node = node->next;
	_nsx_lstadd_atbegin(b, node->next);
	*b = node->next;
	node->next = 0;
	ft_printf("rrb\n");
}
