/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:32:06 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/29 10:25:16 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	_nsx_exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	_nsx_exit_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(0);
}

void	_nsx_exit(int status)
{
	exit(status);
}
