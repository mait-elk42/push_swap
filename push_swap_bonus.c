/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:38:04 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/10 13:30:52 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

int	_nsx_execute_command(char *cmd, t_nsx_node **a, t_nsx_node **b)
{
	if (ft_strnstr(cmd, "sa", 2) && _nsx_strlen(cmd) == 3)
		_nsx_instr_sa(a);
	else if (ft_strnstr(cmd, "sb", 2) && _nsx_strlen(cmd) == 3)
		_nsx_instr_sb(b);
	else if (ft_strnstr(cmd, "ss", 2) && _nsx_strlen(cmd) == 3)
		_nsx_instr_ss(a, b);
	else if (ft_strnstr(cmd, "pa", 2) && _nsx_strlen(cmd) == 3)
		_nsx_instr_pa(a, b);
	else if (ft_strnstr(cmd, "pb", 2) && _nsx_strlen(cmd) == 3)
		_nsx_instr_pb(a, b);
	else if (ft_strnstr(cmd, "ra", 2) && _nsx_strlen(cmd) == 3)
		_nsx_instr_ra(a);
	else if (ft_strnstr(cmd, "rb", 2) && _nsx_strlen(cmd) == 3)
		_nsx_instr_rb(b);
	else if (ft_strnstr(cmd, "rr", 2) && _nsx_strlen(cmd) == 3)
		_nsx_instr_rr(a, b);
	else if (ft_strnstr(cmd, "rra", 3) && _nsx_strlen(cmd) == 4)
		_nsx_instr_rra(a);
	else if (ft_strnstr(cmd, "rrb", 3) && _nsx_strlen(cmd) == 4)
		_nsx_instr_rrb(b);
	else if (ft_strnstr(cmd, "rrr", 3) && _nsx_strlen(cmd) == 4)
		_nsx_instr_rrr(a, b);
	else
		return (-1);
	return (0);
}

void	_nsx_read_instractions(t_nsx_node **a, t_nsx_node **b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		if (_nsx_execute_command(command, a, b) == -1)
		{
			free(command);
			_nsx_lstfree(*a);
			_nsx_lstfree(*b);
			ft_printf("Error\n");
			exit(0);
		}
		free(command);
		command = get_next_line(0);
	}
}

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
	while (numbers[list_length])
		list_length++;
	a = _nsx_2darr2list(numbers);
	_nsx_read_instractions(&a, &b);
	if (_is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	_nsx_lstfree(a);
	return (0);
}
