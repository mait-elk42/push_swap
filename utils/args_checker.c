/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:12:49 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/23 21:56:55 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	_nsx_therenumbers(char *s)
{
	int	yes;

	yes = 0;
	while (*s)
	{
		if (ft_strchr("0123456789", *s))
			yes = 1;
		s++;
	}
	if (!yes)
		_nsx_exit("Where's Numbers!", -1, 'E');
}

void	_nsx_args_checker(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac < 2 || !av[i][j])
		exit(0);
	while (av[i])
	{
		j = 0;
		if (!av[i][j])
			_nsx_exit("Empty Arg!", -1, 'E');
		while (av[i][j])
		{
			if (!ft_strchr("0123456789 -+", av[i][j]))
				_nsx_exit("Expected Numbers Only", -1, 'E');
			if (((ft_strchr("+-", av[i][j])) && !ft_isdigit(av[i][j +1]))
					|| (ft_strchr("-+", av[i][j]) && ft_isdigit(av[i][j -1])))
				_nsx_exit("Syntax Error", -1, 'E');
			j++;
		}
		_nsx_therenumbers(av[i]);
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

void	_nsx_check_length(char *number)
{
	int	l;

	l = 0;
	while (number[l] && ft_strchr("+-0", number[l]))
		l++;
	if (number[0] == '-' && (_nsx_strlen(number + l) > 11
			|| ft_atoi(number) > 0))
		_nsx_exit("Numbers Should Be >= -2147483648 ", -1, 'E');
	if (number[0] != '-' && (_nsx_strlen(number + l) > 10
			|| ft_atoi(number) < 0))
		_nsx_exit("Numbers Should Be <= 2147483647 ", -1, 'E');
}

void	_nsx_num_checker(int ac, char **av)
{
	char	**list;
	int		i;
	int		j;

	i = 0;
	list = _nsx_get_list(ac, av);
	if (!list[1])
		exit(0);
	while (list[i])
	{
		j = 0;
		_nsx_check_length(list[i]);
		while (j < i)
			if (ft_atoi(list[i]) == ft_atoi(list[j++]))
				_nsx_exit("Duplicated Numbers!", -1, 'E');
		i++;
	}
	if (_nsx_is_sorted(list))
		exit(0);
	_nsx_free_2darray(list);
}
