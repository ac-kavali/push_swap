/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:20:18 by achahi            #+#    #+#             */
/*   Updated: 2026/01/02 17:18:12 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_error(void)
{
	ft_putstr_fd("\033[0;31mError\n\033[0m", 2);
	exit(-1);
}

void	stack_print(t_stack *lst)
{
	t_stack	*node;

	if (lst == NULL)
	{
		ft_printf("NULL\n");
		return ;
	}
	node = lst;
	while (node != NULL)
	{
		ft_printf("%i ", (node->value));
		node = node->next;
	}
	ft_printf("\n");
}

int	max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	while (stack != NULL)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	get_pos(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack->value != value)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}
