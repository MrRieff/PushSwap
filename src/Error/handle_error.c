/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:13:39 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/09/03 15:07:13 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// This function will look for any syntax error
int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	return (0);
}

// This function will look for any duplicated number
int	error_dup(t_stack *stack, int number)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->number == number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

// This function will free a stack
void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->number = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

// This function will give a Error message, and free a stack
void	free_errors(t_stack **stack)
{
	free_stack(stack);
	ft_print("Error\n");
	exit(1);
}
