/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr01_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:57:35 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/09 19:07:50 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	_nsx_instr_sa(t_nsx_node **a)
{
	t_nsx_node	*tmp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	ft_printf("sa\n");
}

void	_nsx_instr_sb(t_nsx_node **b)
{
	t_nsx_node	*tmp;

	if (!b || !(*b) || !(*b)->next)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	ft_printf("sb\n");
}

void	_nsx_instr_ss(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node	*tmp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	if (!b || !(*b) || !(*b)->next)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	ft_printf("ss\n");
}

void	_nsx_instr_pa(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node	*node;

	if (!b || !*b)
		return ;
	node = *b;
	(*b) = (*b)->next;
	node->next = 0;
	_nsx_lstadd_atbegin(a, node);
	ft_printf("pa\n");
}

void	_nsx_instr_pb(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node	*node;

	if (!a || !*a)
		return ;
	node = *a;
	(*a) = (*a)->next;
	node->next = 0;
	_nsx_lstadd_atbegin(b, node);
	ft_printf("pb\n");
}
