/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:20:27 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/29 11:44:40 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	_nsx_instr_rrr(t_nsx_node **a, t_nsx_node **b)
{
	t_nsx_node	*node;

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
	ft_printf("rrr\n");
}
