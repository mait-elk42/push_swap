/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:38:04 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/07 06:50:47 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_nsx_node	*a;
	t_nsx_node	*b;
	char		**numbers;
	size_t		list_length;

	a = NULL;
	b = NULL;
	list_length = 0;
	_nsx_args_checker(ac, av);
	numbers = _nsx_get_list(ac, av);
	_nsx_num_checker(ac, av);
	while (numbers[list_length])
		list_length++;
	a = _nsx_2darr2list(numbers);
	if (list_length == 2)
		_nsx_sort_2(&a);
	else if (list_length == 3)
		_nsx_sort_3(&a);
	else if (list_length == 4 || list_length == 5)
		_nsx_sort_4_5(&a, &b);
	else
		_nsx_sort_adv(&a, &b);
}
