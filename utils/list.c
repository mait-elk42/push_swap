/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:19:21 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/08 18:45:58 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_nsx_node	*_nsx_lstnew_node(int num)
{
	t_nsx_node	*node;

	node = _nsx_p_malloc(sizeof(node));
	node->num = num;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	_nsx_lstadd_atlast(t_nsx_node **head, t_nsx_node *new_node)
{
	t_nsx_node	*tmphead;

	if (!new_node)
		return ;
	tmphead = *head;
	if (!tmphead)
	{
		*head = new_node;
		return ;
	}
	while (tmphead->next)
		tmphead = tmphead->next;
	tmphead->next = new_node;
}

void	_nsx_lstadd_atbegin(t_nsx_node **head, t_nsx_node *new_head)
{
	if (!new_head)
		return ;
	if (!(*head))
	{
		*head = new_head;
		return ;
	}
	new_head->next = (*head);
	(*head) = new_head;
}

void	_nsx_lstfree(t_nsx_node *head)
{
	while (head)
	{
		free(head);
		head = head->next;
	}
}

t_nsx_node	*_nsx_2darr2list(char **arr)
{
	t_nsx_node	*head;
	int			i;

	i = 0;
	head = NULL;
	while (arr[i])
	{
		_nsx_lstadd_atlast(&head, _nsx_lstnew_node(ft_atoi(arr[i])));
		i++;
	}
	i = 0;
	while (arr[i])
		free(arr[i++]);
	return (head);
}
