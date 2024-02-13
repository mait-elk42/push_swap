/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:38:04 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/13 09:47:40 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

int	is_valid_command(char	*cmd)
{
	if (!cmd || *cmd == '\n')
		return (0);
	return ((ft_strnstr(cmd, "sa", 2) && ft_strlen(cmd) == 3)
		|| (ft_strnstr(cmd, "sb", 2) && ft_strlen(cmd) == 3)
		|| (ft_strnstr(cmd, "ss", 2) && ft_strlen(cmd) == 3)
		|| (ft_strnstr(cmd, "pa", 2) && ft_strlen(cmd) == 3)
		|| (ft_strnstr(cmd, "pb", 2) && ft_strlen(cmd) == 3)
		|| (ft_strnstr(cmd, "ra", 2) && ft_strlen(cmd) == 3)
		|| (ft_strnstr(cmd, "rb", 2) && ft_strlen(cmd) == 3)
		|| (ft_strnstr(cmd, "rr", 2) && ft_strlen(cmd) == 3)
		|| (ft_strnstr(cmd, "rra", 3) && ft_strlen(cmd) == 4)
		|| (ft_strnstr(cmd, "rrb", 3) && ft_strlen(cmd) == 4)
		|| (ft_strnstr(cmd, "rrr", 3) && ft_strlen(cmd) == 4));
}

void	_nsx_execute_command(char *cmd, t_nsx_node **a, t_nsx_node **b)
{
	if (ft_strnstr(cmd, "sa", 2) && ft_strlen(cmd) == 2)
		_nsx_instr_sa(a);
	if (ft_strnstr(cmd, "sb", 2) && ft_strlen(cmd) == 2)
		_nsx_instr_sb(b);
	if (ft_strnstr(cmd, "ss", 2) && ft_strlen(cmd) == 2)
		_nsx_instr_ss(a, b);
	if (ft_strnstr(cmd, "pa", 2) && ft_strlen(cmd) == 2)
		_nsx_instr_pa(a, b);
	if (ft_strnstr(cmd, "pb", 2) && ft_strlen(cmd) == 2)
		_nsx_instr_pb(a, b);
	if (ft_strnstr(cmd, "ra", 2) && ft_strlen(cmd) == 2)
		_nsx_instr_ra(a);
	if (ft_strnstr(cmd, "rb", 2) && ft_strlen(cmd) == 2)
		_nsx_instr_rb(b);
	if (ft_strnstr(cmd, "rr", 2) && ft_strlen(cmd) == 2)
		_nsx_instr_rr(a, b);
	if (ft_strnstr(cmd, "rra", 3) && ft_strlen(cmd) == 3)
		_nsx_instr_rra(a);
	if (ft_strnstr(cmd, "rrb", 3) && ft_strlen(cmd) == 3)
		_nsx_instr_rrb(b);
	if (ft_strnstr(cmd, "rrr", 3) && ft_strlen(cmd) == 3)
		_nsx_instr_rrr(a, b);
}

void	_nsx_read_instractions(t_nsx_node **a, t_nsx_node **b, char **cmds)
{
	int	i;

	i = 0;
	if (!cmds)
		return ;
	while (cmds[i])
	{
		_nsx_execute_command(cmds[i], a, b);
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

char	**_nsx_read_commands(void)
{
	char	**res;
	char	*tmp;
	char	*all_c;
	char	*all_commands;

	all_commands = NULL;
	tmp = get_next_line(0);
	while (tmp)
	{
		if (!is_valid_command(tmp))
			(free(tmp), free(all_commands), _nsx_exit_error());
		all_c = all_commands;
		all_commands = ft_strjoin(all_c, tmp);
		free(tmp);
		free(all_c);
		if (!all_commands)
			_nsx_exit_error();
		tmp = get_next_line(0);
	}
	res = ft_split(all_commands, '\n');
	free(all_commands);
	return (res);
}

int	main(int ac, char **av)
{
	t_nsx_node	*a;
	t_nsx_node	*b;
	char		**numbers;
	char		**commands;

	a = NULL;
	b = NULL;
	_nsx_args_checker(ac, av);
	numbers = _nsx_get_list(ac, av);
	a = _nsx_2darr2list(numbers);
	commands = _nsx_read_commands();
	_nsx_read_instractions(&a, &b, commands);
	if (_is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	_nsx_lstfree(a);
	_nsx_lstfree(b);
	return (0);
}
