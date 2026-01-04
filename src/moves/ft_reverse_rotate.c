/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 09:47:44 by achahi            #+#    #+#             */
/*   Updated: 2026/01/01 18:11:15 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	*rra(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*last;
	int		i;
	int		len_a;

	len_a = stack_size(*stack_a);
	if (len_a <= 1)
		return ("");
	i = 0;
	last = *stack_a;
	while (i < len_a - 2)
	{
		last = last->next;
		i++;
	}
	aux = last->next;
	last->next = NULL;
	aux->next = *stack_a;
	*stack_a = aux;
	return ("rra\n");
}

char	*rrb(t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*last;
	int		i;
	int		len_b;

	len_b = stack_size(*stack_b);
	if (len_b <= 1)
		return ("");
	i = 0;
	last = *stack_b;
	while (i < len_b - 2)
	{
		last = last->next;
		i++;
	}
	aux = last->next;
	last->next = NULL;
	aux->next = *stack_b;
	*stack_b = aux;
	return ("rrb\n");
}

char	*rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	return ("rrr\n");
}
