/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:25:16 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/24 16:27:25 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*next;
}				t_node;

t_node	*ft_create_node(int number);
t_node	*ft_get_last(t_node *head);
int		ft_stack_size(t_node *head);
void	ft_add_node_front(t_node **stack, t_node *new_node);
void	ft_add_node_back(t_node **stack, t_node *new_node);
void	ft_init_stack(t_node **stack, int argc, char **argv);
bool	ft_is_sorted_stack(t_node **stack);
int		ft_get_distance_node(t_node **stack, int index);
void	ft_free_stack(t_node **stack);
void	ft_error_msg(char *msg);
void	ft_free(char **str);
void	ft_check_args(int argc, char **argv);
void	ft_print_linked_list(t_node *head);

bool	ft_sa(t_node **stack_a);
bool	ft_sb(t_node **stack_b);
bool	ft_ss(t_node **stack_a, t_node **stack_b);
bool	ft_pa(t_node **stack_a, t_node **stack_b);
bool	ft_pb(t_node **stack_b, t_node **stack_a);
bool	ft_ra(t_node **stack_a);
bool	ft_rb(t_node **stack_b);
bool	ft_rr(t_node **stack_a, t_node **stack_b);
bool	ft_rra(t_node **stack_a);
bool	ft_rrb(t_node **stack_b);
bool	ft_rrr(t_node **stack_a, t_node **stack_b);

bool	ft_push(t_node **stack_from, t_node **stack_dst);
bool	ft_swap(t_node **stack);
bool	ft_shift_up(t_node **stack);
bool	ft_shift_down(t_node **stack);

int		ft_get_max_bits(t_node **stack);
int		ft_min(t_node **stack, int number);
void	ft_sort_three(t_node **stack_a);
void	ft_sort_four(t_node **stack_a, t_node **stack_b);
void	ft_sort_five(t_node **stack_a, t_node **stack_b);

void	ft_radix_sort(t_node **stack_a, t_node **stack_b);
void	ft_simple_sort(t_node **stack_a, t_node **stack_b);
void	ft_index_stack(t_node **stack);

bool	ft_operations_stack_one(char *line, t_node **stack_a, t_node **stack_b);
bool	ft_operations_stack_two(char *line, t_node **stack_a, t_node **stack_b);
bool	ft_operations_stack_three(char *line, t_node **stack_a,
			t_node **stack_b);

#endif