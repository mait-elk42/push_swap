/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:12:49 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/23 13:36:18 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	_nsx_args_checker(int ac, char **av)
{
	int	i;
	int	j;
	int ch;

	i = 1;
	j = 0;
	if (ac < 2 || !av[i][j])
		_nsx_exit("Invalid Args", -1, 'E');
	while (av[i])
	{
		ch = 0;
		j = 0;
		if (!av[i][j])
			_nsx_exit("Empty Arg!", -1, 'E');
		while (av[i][j])
		{
			ch += (ft_strchr("0123456789", av[i][j]) != 0);
			if (!ft_strchr("0123456789 -+", av[i][j]))
				_nsx_exit("Expected Numbers Only", -1, 'E');
			if (((av[i][j] == '+' || av[i][j] == '-') && !ft_isdigit(av[i][j+1]))
					|| ((ft_isdigit(av[i][j+1])) && av[i][j+1] == ' '))
				_nsx_exit("Syntax Error", -1, 'E');
			j++;
		}
		if (!ch)
			_nsx_exit("Where's Numbers!", -1, 'E');
		i++;
	}
}

int	_nsx_is_sorted(char **list)
{
	int	i;
	int	ok;

	i = 1;
	ok = 0;
	while (list[i])
	{
		if (ft_atoi(list[i]) > ft_atoi(list[i - 1]))
			ok++;
		i++;
	}
	return (i - 1 == ok);
}

void	_nsx_num_checker(int ac, char **av)
{
	char	**list;
	int		i;
	int		j;

	i = 0;
	list = _nsx_get_list(ac, av);
	if (!list[1])
		_nsx_exit("+1 NUMB", 0, 'E');
	while (list[i])
	{
		j = 0;
		if (list[i][0] == '-' && (_nsx_strlen(list[i]) > 11 || ft_atoi(list[i]) > 0))
			_nsx_exit("Numbers Should Be >= -2147483648 ", -1, 'E');
		if (list[i][0] != '-' && (_nsx_strlen(list[i]) > 10 || ft_atoi(list[i]) < 0))
			_nsx_exit("Numbers Should Be <= 2147483647 ", -1, 'E');
		while (j < i)
			if (ft_atoi(list[i]) == ft_atoi(list[j++]))
				_nsx_exit("Duplicated Numbers!", -1, 'E');
		i++;
	}
	if (_nsx_is_sorted(list))
		_nsx_exit("Sorted Numbers !", -1, 'E');
	_nsx_free_2darray(list);
}
