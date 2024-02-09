/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:48:56 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/09 10:12:28 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	_nsx_exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

char	**_nsx_get_list(int ac, char **av)
{
	char	**list;
	int		i;
	char	*all_av;
	char	*tmp;

	all_av = NULL;
	i = 1;
	while (i < ac)
	{
		tmp = ft_strjoin(all_av, av[i]);
		if (!tmp)
			_nsx_exit_error();
		free(all_av);
		all_av = ft_strjoin(tmp, " ");
		if (!tmp)
			_nsx_exit_error();
		free(tmp);
		i++;
	}
	list = ft_split(all_av, ' ');
	free(all_av);
	if (!list)
		exit(0);
	return (list);
}
