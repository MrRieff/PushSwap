/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:38:03 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/09/04 13:58:04 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// This function will push from a stack to another stack
void	push(t_stack **dest_stack, t_stack **src_stack)
{
	t_stack	*node_to_push;

	if (!*src_stack)
		return ;
	node_to_push = *src_stack;
	*src_stack = (*src_stack)->next;
	if (*src_stack)
		(*src_stack)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest_stack)
	{
		*dest_stack = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest_stack;
		node_to_push->next->prev = node_to_push;
		*dest_stack = node_to_push;
	}
}

// This function will swap the top node in a stack with
// the second node in a stack
void	swap(t_stack **head_node)
{
	if (!*head_node || !(*head_node)->next)
		return ;
	*head_node = (*head_node)->next;
	(*head_node)->prev->prev = *head_node;
	(*head_node)->prev->next = (*head_node)->next;
	if ((*head_node)->next)
		(*head_node)->next->prev = (*head_node)->prev;
	(*head_node)->next = (*head_node)->prev;
	(*head_node)->prev = NULL;
}

// This function will rotate the top node in a
//stack to the last position of a stack
void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

// This function will rotate the last node in a
//stack to the top position in the stack
void	rev_rotate(t_stack **stack)
{
	t_stack	*first_node;

	if (!stack || !(*stack)->next)
		return ;
	first_node = find_last(*stack);
	first_node->prev->next = NULL;
	first_node->next = *stack;
	first_node->prev = NULL;
	*stack = first_node;
	first_node->next->prev = first_node;
}
