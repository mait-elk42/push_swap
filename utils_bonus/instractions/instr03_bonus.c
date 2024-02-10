/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr03_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:20:27 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/10 12:36:37 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	_nsx_instr_rrr(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node	*node;

	if (!a || !b || !*a || !*b || !(*a)->next || !(*b)->next)
		return ;
	node = *a;
	while (node->next->next)
		node = node->next;
	_nsx_lstadd_atbegin(a, node->next);
	*a = node->next;
	node->next = 0;
	node = *b;
	while (node->next->next)
		node = node->next;
	_nsx_lstadd_atbegin(b, node->next);
	*b = node->next;
	node->next = 0;
}
