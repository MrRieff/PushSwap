/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualbuqu <lualbuqu@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:03:56 by lualbuqu          #+#    #+#             */
/*   Updated: 2024/09/03 14:22:53 by lualbuqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// Definition: This function returns the lenght of a stack
int	stack_len(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

// This funtion returns the last node of a stack
t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// This function returns the smallest node of a stack
t_stack	*find_min(t_stack *stack)
{
	long	smallest_value;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	smallest_value = LONG_MAX;
	while (stack)
	{
		if (stack->number < smallest_value)
		{
			smallest_value = stack->number;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

// This function returns the biggest node in a stack
t_stack	*find_max(t_stack *stack)
{
	long	biggest_value;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	biggest_value = LONG_MIN;
	while (stack)
	{
		if (stack->number > biggest_value)
		{
			biggest_value = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

// This function prints a string
void	ft_print(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}
