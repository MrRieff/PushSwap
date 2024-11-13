/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:26:04 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/09/04 13:59:27 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// Rotate A & print move
void	ra(t_stack **stack_a, bool is_printable)
{
	rotate(stack_a);
	if (is_printable)
		ft_print("ra\n");
}

// Rotate B & print move
void	rb(t_stack **stack_b, bool is_printable)
{
	rotate(stack_b);
	if (is_printable)
		ft_print("rb\n");
}

// Rotate BOTH & print move
void	rr(t_stack **stack_a, t_stack **stack_b, bool is_printable)
{
	rotate(stack_a);
	rotate(stack_b);
	if (is_printable)
		ft_print("rr\n");
}
