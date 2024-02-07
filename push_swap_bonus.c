/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:38:04 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/07 06:43:25 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>

void	_nsx_mini_api(char *instr, t_nsx_node **a, t_nsx_node **b)
{
	if (ft_strnstr(instr, "sa", 2))
		_nsx_instr_sa(a);
	else if (ft_strnstr(instr, "sb", 2))
		_nsx_instr_sb(b);
	else if (ft_strnstr(instr, "ss", 2))
		_nsx_instr_ss(a, b);
	else if (ft_strnstr(instr, "pa", 2))
		_nsx_instr_pa(a, b);
	else if (ft_strnstr(instr, "pb", 2))
		_nsx_instr_pb(a, b);
	else if (ft_strnstr(instr, "ra", 2))
		_nsx_instr_ra(a);
	else if (ft_strnstr(instr, "rb", 2))
		_nsx_instr_rb(b);
	else if (ft_strnstr(instr, "rr", 2))
		_nsx_instr_rr(a, b);
	else if (ft_strnstr(instr, "rra", 3))
		_nsx_instr_rra(a);
	else if (ft_strnstr(instr, "rrb", 3))
		_nsx_instr_rrb(b);
	else if (ft_strnstr(instr, "rrr", 3))
		_nsx_instr_rrr(a, b);
	else
		_nsx_exit_error();
}

int	main(int ac, char **av)
{
	t_nsx_node	*a;
	t_nsx_node	*b;
	char		**numbers;
	char		*instr;

	a = NULL;
	b = NULL;
	_nsx_args_checker(ac, av);
	numbers = _nsx_get_list(ac, av);
	_nsx_num_checker(ac, av);
	a = _nsx_2darr2list(numbers);
	instr = get_next_line(0);
	while (instr)
	{
		_nsx_mini_api(instr, &a, &b);
		free(instr);
		instr = get_next_line(0);
	}
	if (_is_sorted(a))
		ft_printf("OK");
	else
		ft_printf("KO");
}
