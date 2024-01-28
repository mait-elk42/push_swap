/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:44:28 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/27 18:34:39 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft_advanced/libft.h"

typedef struct s_nsx_node
{
	int					num;
	struct s_nsx_node	*next;
}	t_nsx_node;

void	_nsx_args_checker(int ac, char **av);
void	_nsx_num_checker(int ac, char **av);
void	_nsx_exit_msg(char *msg);
void	_nsx_exit_error();
void	_nsx_exit(int status);
void	_nsx_free_2darray(char **arr);
char	**_nsx_get_list(int ac, char **av);

t_nsx_node	*_nsx_lstnew_node(int num);
void	_nsx_lstadd_atlast(t_nsx_node **head, t_nsx_node *new_node);
void	_nsx_lstadd_atbegin(t_nsx_node **head, t_nsx_node *new_head);
void	_nsx_lstfree(t_nsx_node *head);
t_nsx_node	*_nsx_2darr2list(char **arr);

void	*_nsx_p_malloc(size_t size);

void	_nsx_instr_sa(t_nsx_node *a);
void	_nsx_instr_sb(t_nsx_node *a);
void	_nsx_instr_ss(t_nsx_node *a, t_nsx_node *b);

void	_nsx_instr_pa(t_nsx_node **a, t_nsx_node **b);
void	_nsx_instr_pb(t_nsx_node **a, t_nsx_node **b);

void	_nsx_instr_ra(t_nsx_node **a, t_nsx_node **b);
void	_nsx_instr_rb(t_nsx_node **a, t_nsx_node **b);
void	_nsx_instr_rr(t_nsx_node **a, t_nsx_node **b);

void	_nsx_instr_rra(t_nsx_node **a, t_nsx_node **b);
void	_nsx_instr_rrb(t_nsx_node **a, t_nsx_node **b);
void	_nsx_instr_rrr(t_nsx_node **a, t_nsx_node **b);

#endif