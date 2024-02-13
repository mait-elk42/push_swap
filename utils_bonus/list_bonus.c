/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:19:21 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/12 13:55:19 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

t_nsx_node	*_nsx_lstnew_node(int num)
{
	t_nsx_node	*node;

	node = malloc(sizeof(node));
	if (!node)
		return (NULL);
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
	t_nsx_node	*save;

	while (head)
	{
		save = head->next;
		free(head);
		head = save;
	}
}

t_nsx_node	*_nsx_2darr2list(char **arr)
{
	t_nsx_node	*head;
	t_nsx_node	*tmpnode;
	int			i;

	i = 0;
	head = NULL;
	while (arr[i])
	{
		tmpnode = _nsx_lstnew_node(ft_atoi(arr[i]));
		if (!tmpnode)
		{
			_nsx_2darray_free(arr);
			_nsx_lstfree(head);
			_nsx_exit_error();
		}
		_nsx_lstadd_atlast(&head, tmpnode);
		i++;
	}
	_nsx_2darray_free(arr);
	return (head);
}
