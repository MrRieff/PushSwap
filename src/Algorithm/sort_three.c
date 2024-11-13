/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:28:52 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/09/03 14:23:46 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// This function sorts when there are only 3 nodes in a stack
void	sort_three(t_stack **stack_a)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a, true);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a, true);
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a, true);
}
