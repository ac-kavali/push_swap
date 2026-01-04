/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:43:42 by achahi            #+#    #+#             */
/*   Updated: 2026/01/01 00:33:17 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*ra(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*current;

	if (stack_size(*stack_a) <= 1)
		return ("");
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	current = *stack_a;
	while (current->next)
		current = current->next;
	current->next = aux;
	aux->next = NULL;
	return ("ra\n");
}

char	*rb(t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*current;

	if (stack_size(*stack_b) <= 1)
		return ("");
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	current = *stack_b;
	while (current->next)
		current = current->next;
	current->next = aux;
	aux->next = NULL;
	return ("rb\n");
}

char	*rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	return ("rr\n");
}
