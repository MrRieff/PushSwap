/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:22:49 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/09/04 13:59:36 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// Swap A & print move
void	sa(t_stack **stack_a, bool is_printable)
{
	swap(stack_a);
	if (is_printable)
		ft_print("sa\n");
}

// Swap B & print move
void	sb(t_stack **stack_b, bool is_printable)
{
	swap(stack_b);
	if (is_printable)
		ft_print("sb\n");
}

// Swap BOTH & print move
void	ss(t_stack **stack_a, t_stack **stack_b, bool is_printable)
{
	swap(stack_a);
	swap(stack_b);
	if (is_printable)
		ft_print("ss\n");
}
