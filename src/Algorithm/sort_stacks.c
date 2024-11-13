/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:28:29 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/09/04 13:49:57 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// Definition: moves the cheapest node from stack A to stack B
static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		while (*stack_b != cheapest_node->target_node
			&& *stack_a != cheapest_node)
			rr(stack_a, stack_b, true);
		current_index(*stack_a);
		current_index(*stack_b);
	}
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
	{
		while (*stack_b != cheapest_node->target_node
			&& *stack_a != cheapest_node)
			rrr(stack_a, stack_b, true);
		current_index(*stack_a);
		current_index(*stack_b);
	}
	prep_to_push(stack_a, cheapest_node, 'a');
	prep_to_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_b, stack_a, true);
}

// Moves the node on top of stack B to stack A
static void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_to_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b, true);
}

// Rotates a stack until the desired node to push is on top
void	prep_to_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

// This function rotates the nodes within a stack,
// until the smallest node is on top
static void	min_on_top(t_stack **stack_a)
{
	while ((*stack_a)->number != find_min(*stack_a)->number)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a, true);
		else
			rra(stack_a, true);
	}
}

// This function sorts stack A when there are more than 3 nodes
void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len_stack_a;

	len_stack_a = stack_len(*stack_a);
	if (len_stack_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_b, stack_a, true);
	if (len_stack_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_b, stack_a, true);
	while (len_stack_a-- > 3 && !is_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}
