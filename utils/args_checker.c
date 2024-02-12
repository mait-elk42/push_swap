/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:12:49 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/12 09:01:23 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	_nsx_local_atoi(char *num, int *error)
{
	long	r;
	int		sign;

	r = 0;
	sign = 1;
	*error = 0;
	while ((*num >= 9 && *num <= 13) || *num == ' ')
		num++;
	if (*num == '-' || *num == '+')
	{
		if (*num == '-')
			sign = -1;
		num++;
	}
	while (*num && (*num >= '0' && *num <= '9'))
	{
		r = (r * 10) + (*num - 48);
		if ((sign == 1 && r > 2147483647) || (sign == -1 && r > 2147483648))
			return (*error = 1, 0);
		num++;
	}
	return (sign * r);
}

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

void	_nsx_2darray_checker(int ac, char **av)
{
	char	**list;
	int		i;
	int		j;
	int		atoi_error;

	i = 0;
	list = _nsx_get_list(ac, av);
	while (list[i])
	{
		j = 0;
		if (_nsx_local_atoi(list[i], &atoi_error) == 0 && atoi_error)
			(_nsx_2darray_free(list), _nsx_exit_error());
		while (j < i)
			if (ft_atoi(list[i]) == ft_atoi(list[j++]))
				(_nsx_2darray_free(list), _nsx_exit_error());
		i++;
	}
	_nsx_2darray_free(list);
}

void	_nsx_args_checker(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac < 2)
		exit(0);
	if (!av[i][j])
		_nsx_exit_error();
	while (av[i])
	{
		j = 0;
		if (!av[i][j])
			_nsx_exit_error();
		while (av[i][j])
		{
			if (((ft_strchr("+-", av[i][j])) && !ft_isdigit(av[i][j + 1]))
					|| (ft_strchr("-+", av[i][j]) && ft_isdigit(av[i][j - 1]))
					|| (!ft_strchr("0123456789 -+", av[i][j])))
				_nsx_exit_error();
			j++;
		}
		_nsx_therenumbers(av[i++]);
	}
	_nsx_2darray_checker(ac, av);
}
