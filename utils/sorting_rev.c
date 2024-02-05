/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:55:50 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/05 09:40:52 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	_nsx_sort_reversed(t_nsx_node **a, t_nsx_node **b)
{
	while (*a)
	{
		_nsx_instr_pb(a, b);
		_nsx_instr_rb(b);
	}
	while (*b)
		_nsx_instr_pa(a, b);
}