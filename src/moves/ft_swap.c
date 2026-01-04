/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:28:04 by achahi            #+#    #+#             */
/*   Updated: 2026/01/01 22:39:23 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*sa(t_stack **stack_a)
{
	t_stack	*tmp;

	if (stack_size(*stack_a) <= 1)
		return ("");
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	return ("sa\n");
}

char	*sb(t_stack **stack_b)
{
	t_stack	*tmp;

	if (stack_size(*stack_b) <= 1)
		return ("");
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	return ("sb\n");
}

char	*ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	return ("ss\n");
}
