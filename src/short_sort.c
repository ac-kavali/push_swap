/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:27:07 by achahi            #+#    #+#             */
/*   Updated: 2026/01/03 02:18:58 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_six(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	bring_to_top(stack_a, min);
	write(1, pb(stack_a, stack_b), 3);
	min = get_min(*stack_a);
	bring_to_top(stack_a, min);
	write(1, pb(stack_a, stack_b), 3);
	sort_four(stack_a, stack_b);
	write(1, pa(stack_a, stack_b), 3);
	write(1, pa(stack_a, stack_b), 3);
}

void	sort_three(t_stack **stack_a)
{
	int	one;
	int	two;
	int	three;

	one = (*stack_a)->value;
	two = (*stack_a)->next->value;
	three = (*stack_a)->next->next->value;
	if (one < two && two > three && one < three)
	{
		write(1, ra(stack_a), 3);
		write(1, sa(stack_a), 3);
		write(1, rra(stack_a), 4);
	}
	else if (one > two && two > three && one > three)
	{
		write(1, sa(stack_a), 3);
		write(1, rra(stack_a), 4);
	}
	else if (one > two && two < three && one < three)
		write(1, sa(stack_a), 3);
	else if (one < two && two > three && one > three)
		write(1, rra(stack_a), 4);
	else if (one > two && two < three && one > three)
		write(1, ra(stack_a), 3);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	bring_to_top(stack_a, min);
	write(1, pb(stack_a, stack_b), 3);
	min = get_min(*stack_a);
	bring_to_top(stack_a, min);
	write(1, pb(stack_a, stack_b), 3);
	sort_three(stack_a);
	write(1, pa(stack_a, stack_b), 3);
	write(1, pa(stack_a, stack_b), 3);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	bring_to_top(stack_a, min);
	write(1, pb(stack_a, stack_b), 3);
	sort_three(stack_a);
	write(1, pa(stack_a, stack_b), 3);
}

void	short_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		write(1, sa(stack_a), 3);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else if (size == 6)
		sort_six(stack_a, stack_b);
}
