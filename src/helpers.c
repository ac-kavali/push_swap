/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:24:27 by achahi            #+#    #+#             */
/*   Updated: 2026/01/02 17:17:05 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fexit_error(char *s2, char *s1, char **matrix)
{
	free(s1);
	free(s2);
	free_matrix(matrix);
	ft_putstr_fd("\033[0;31mError\n\033[0m", 2);
	exit(-1);
}

int	get_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	bring_to_top(t_stack **stack, int value)
{
	int	pos;
	int	size;

	pos = get_pos(*stack, value);
	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while ((*stack)->value != value)
			write (1, ra(stack), 3);
	}
	else
		while ((*stack)->value != value)
			write(1, rra(stack), 4);
}

int	ft_issorted(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	len;

	if (stack_size(stack_b) != 0)
		return (0);
	i = 0;
	len = stack_size(stack_a);
	while ((len - 1) > i)
	{
		if (get(stack_a, i)->value > get(stack_a, i + 1)->value)
			return (0);
		i++;
	}
	return (1);
}

void	free_stacks(t_stack **stack)
{
	if (*stack == NULL)
		return ;
	if ((*stack)->next != NULL)
		free_stacks(&(*stack)->next);
	(free(*stack), *stack = NULL);
}
