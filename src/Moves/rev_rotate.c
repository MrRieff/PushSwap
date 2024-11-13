/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:25:29 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/09/04 13:59:08 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// Reverse Rotate A & print move
void	rra(t_stack **stack_a, bool is_printable)
{
	rev_rotate(stack_a);
	if (is_printable)
		ft_print("rra\n");
}

// Reverse Rotate B & print move
void	rrb(t_stack **stack_b, bool is_printable)
{
	rev_rotate(stack_b);
	if (is_printable)
		ft_print("rrb\n");
}

// Reverse Rotate BOTH & print  move
void	rrr(t_stack **stack_a, t_stack **stack_b, bool is_printable)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (is_printable)
		ft_print("rrr\n");
}
