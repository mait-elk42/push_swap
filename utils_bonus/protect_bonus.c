/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:42:01 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/07 03:29:35 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	*_nsx_p_malloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		_nsx_exit_error();
	return (mem);
}
