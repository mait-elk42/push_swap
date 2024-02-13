/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:44:28 by mait-elk          #+#    #+#             */
/*   Updated: 2024/02/13 09:37:03 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft_advanced/libft.h"

typedef struct s_nsx_node
{
	int					index;
	int					num;
	struct s_nsx_node	*next;
}	t_nsx_node;

void		_nsx_args_checker(int ac, char **av);
void		_nsx_2darray_checker(int ac, char **av);
void		_nsx_exit_error(void);
char		**_nsx_get_list(int ac, char **av);

t_nsx_node	*_nsx_lstnew_node(int num);
void		_nsx_lstadd_atlast(t_nsx_node **head, t_nsx_node *new_node);
void		_nsx_lstadd_atbegin(t_nsx_node **head, t_nsx_node *new_head);
void		_nsx_lstfree(t_nsx_node *head);
t_nsx_node	*_nsx_2darr2list(char **arr);

void		_nsx_instr_sa(t_nsx_node **a);
void		_nsx_instr_sb(t_nsx_node **b);
void		_nsx_instr_ss(t_nsx_node **a, t_nsx_node **b);

void		_nsx_instr_pa(t_nsx_node **a, t_nsx_node **b);
void		_nsx_instr_pb(t_nsx_node **a, t_nsx_node **b);

void		_nsx_instr_ra(t_nsx_node **a);
void		_nsx_instr_rb(t_nsx_node **b);
void		_nsx_instr_rr(t_nsx_node **a, t_nsx_node **b);

void		_nsx_instr_rra(t_nsx_node **a);
void		_nsx_instr_rrb(t_nsx_node **b);
void		_nsx_instr_rrr(t_nsx_node **a, t_nsx_node **b);

void		_nsx_sort_2(t_nsx_node **a);
void		_nsx_sort_3(t_nsx_node **a);
void		_nsx_sort_4_5(t_nsx_node **a, t_nsx_node **b);
void		_nsx_sort_adv(t_nsx_node **a, t_nsx_node **b);

t_nsx_node	*_get_last_node(t_nsx_node *head);
int			list_length(t_nsx_node *head);
int			get_index(t_nsx_node *head, int wanted);
void		_list_indexing(t_nsx_node *head);
int			_is_sorted(t_nsx_node *a_head);
void		_nsx_2darray_free(char **arr);

#endif
