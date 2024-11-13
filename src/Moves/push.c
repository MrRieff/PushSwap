/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:21:16 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/09/04 13:58:34 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// Push A & print move
void	pa(t_stack **stack_a, t_stack **stack_b, bool is_printable)
{
	push(stack_a, stack_b);
	if (is_printable)
		ft_print("pa\n");
}

// Push B & print mob
void	pb(t_stack **stack_b, t_stack **stack_a, bool is_printable)
{
	push(stack_b, stack_a);
	if (is_printable)
		ft_print("pb\n");
}
