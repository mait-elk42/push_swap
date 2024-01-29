/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:12:49 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/29 10:26:53 by mait-elk         ###   ########.fr       */
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
		_nsx_exit_error();
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
			_nsx_exit_error();
		while (av[i][j])
		{
			if (!ft_strchr("0123456789 -+", av[i][j]))
				_nsx_exit_error();
			if (((ft_strchr("+-", av[i][j])) && !ft_isdigit(av[i][j +1]))
					|| (ft_strchr("-+", av[i][j]) && ft_isdigit(av[i][j -1])))
				_nsx_exit_error();
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

int	overflow_catcher(char *str, int _is_negative)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (_is_negative && _nsx_strlen(str) >= 11 && str[i] > "-2147483648"[i])
			_nsx_exit_error();
		if (!_is_negative && _nsx_strlen(str) >= 10 && str[i] > "2147483647"[i])
			_nsx_exit_error();
		i++;
	}
	return (0);
}

void	_nsx_check_length(char *number)
{
	int	l;

	l = 0;
	while (number[l] && ft_strchr("+-0", number[l]))
		l++;
	if (number[0] == '-' && (_nsx_strlen(number + l) > 11
			|| ft_atoi(number) > 0))
		_nsx_exit_error();
	if (number[0] != '-' && (_nsx_strlen(number + l) > 10
			|| ft_atoi(number) < 0))
		_nsx_exit_error();
	overflow_catcher(number, number[0] == '-');
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
				_nsx_exit_error();
		i++;
	}
	if (_nsx_is_sorted(list))
		exit(0);
	_nsx_free_2darray(list);
}
