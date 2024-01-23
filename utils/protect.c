/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:42:01 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/23 18:43:41 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	*_nsx_p_malloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		return (0);
	return (mem);
}