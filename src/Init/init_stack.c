/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:40:33 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/09/04 13:57:44 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// Definition: This function will transform a
// string of ascii to long intergers
static long	ft_atol(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str <= ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result * sign);
}

// Definition: This function will add a new node
//to a double linked list
static void	append_node(t_stack **stack, int number)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->number = number;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

// Definition: This function initializes a
// double linked list with intergers from an array of strings
void	init_stack(t_stack **stack_a, char **av)
{
	long	number;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_errors(stack_a);
		number = ft_atol(av[i]);
		if (number > INT_MAX || number < INT_MIN)
			free_errors(stack_a);
		if (error_dup(*stack_a, (int)number))
			free_errors(stack_a);
		append_node(stack_a, (int)number);
		i++;
	}
}

// Definition: This function checks if the attribute 'cheapest' is true,
// stopping when it finds it, and returns it
t_stack	*get_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
