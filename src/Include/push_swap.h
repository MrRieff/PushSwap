/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:56:37 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/08/28 20:54:40 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// LIBRARIES

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// STRUCT

typedef struct s_stack
{
	int				number;
	int				index;
	int				push_cost;

	bool			above_median;
	bool			cheapest;

	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// INIT
void				init_stack(t_stack **stack_a, char **av);
void				init_nodes_a(t_stack *stack_a, t_stack *stack_b);
void				init_nodes_b(t_stack *stack_a, t_stack *stack_b);
void				set_cheapest(t_stack *stack);
t_stack				*get_cheapest_node(t_stack *stack);
void				current_index(t_stack *stack);

// UTILS
int					stack_len(t_stack *stack);
t_stack				*find_last(t_stack *stack);
t_stack				*find_min(t_stack *stack);
t_stack				*find_max(t_stack *stack);
void				ft_print(char *str);
char				**ft_split(char *s, char c);

// SORT
bool				is_sorted(t_stack *stack);
void				sort_stacks(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack_a);

// PREP
void				prep_to_push(t_stack **stack, t_stack *top_node,
						char stack_name);

// OPERATIONS
void				push(t_stack **dest_stack, t_stack **src_stack);
void				swap(t_stack **head_node);
void				rotate(t_stack **stack);
void				rev_rotate(t_stack **stack);

// MOVES
void				sa(t_stack **stack_a, bool is_printable);
void				sb(t_stack **stack_b, bool is_printable);
void				ss(t_stack **stack_a, t_stack **stack_b, bool is_printable);

void				pa(t_stack **stack_a, t_stack **stack_b, bool is_printable);
void				pb(t_stack **stack_b, t_stack **stack_a, bool is_printable);

void				ra(t_stack **stack_a, bool is_printable);
void				rb(t_stack **stack_b, bool is_printable);
void				rr(t_stack **stack_a, t_stack **stack_b, bool is_printable);

void				rra(t_stack **stack_a, bool is_printable);
void				rrb(t_stack **stack_b, bool is_printable);
void				rrr(t_stack **stack_a, t_stack **stack_b,
						bool is_printable);

// ERROR
int					error_syntax(char *str);
int					error_dup(t_stack *stack, int number);
void				free_stack(t_stack **stack);
void				free_errors(t_stack **stack);

#endif