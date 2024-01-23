/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:48:56 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/23 15:20:12 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
			_nsx_exit("Strjoin Err", -1, 'E');
		free(all_av);
		all_av = ft_strjoin(tmp, " ");
		if (!tmp)
			_nsx_exit("Strjoin Err", -1, 'E');
		free(tmp);
		i++;
	}
	list = ft_split(all_av, ' ');
	free(all_av);
	if (!list)
		_nsx_exit("Split Error", -1, 'E');
	return (list);
}
