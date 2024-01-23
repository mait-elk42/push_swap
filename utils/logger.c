/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:32:06 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/23 10:34:45 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	_nsx_exit(char *msg, int status, char type)
{
	if (type == 'E')
		ft_printf("\033[31mError :\n[ %s ]\033[0m\n", msg);
	else
		ft_printf("\033[34mMessage :\n[ %s ]\033[0m\n", msg);
	exit(status);
}
