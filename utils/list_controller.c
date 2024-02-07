/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:16:41 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/07 20:00:08 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	list_length(t_nsx_node *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

t_nsx_node	*_get_last_node(t_nsx_node *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

int	get_wanted_index(t_nsx_node *b, int wanted)
{
	int	i;

	i = 0;
	while (b)
	{
		if (b->index == wanted)
			return (i);
		i++;
		b = b->next;
	}
	return (-1);
}

int	_is_not_sorted(t_nsx_node *a_head)
{
	if (!a_head)
		return (-1);
	while (a_head->next)
	{
		if (a_head->num > a_head->next->num)
			return (1);
		a_head = a_head->next;
	}
	return (0);
}

void	_list_indexing(t_nsx_node *head)
{
	t_nsx_node	*save_head;
	t_nsx_node	*tmp;

	save_head = head;
	while (head)
	{
		tmp = save_head;
		while (tmp)
		{
			if (head->num > tmp->num)
				head->index++;
			tmp = tmp->next;
		}
		head = head->next;
	}
}