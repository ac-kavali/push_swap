/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 15:56:12 by achahi            #+#    #+#             */
/*   Updated: 2026/01/03 00:34:13 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	move_stack(t_stack **stack_a, t_stack **stack_b, int pos)
{
	int	i;

	i = 0;
	while (ft_abs(get(*stack_a, pos)->steps_a) > i)
	{
		if (get(*stack_a, pos)->steps_a > 0)
			write(1, ra(stack_a), 3);
		else
			write(1, rra(stack_a), 4);
		pos = min_steps(stack_a);
		i++;
	}
	i = 0;
	while (ft_abs(get(*stack_a, pos)->steps_b) > i)
	{
		if (get(*stack_a, pos)->steps_b > 0)
			write(1, rb(stack_b), 3);
		else
			write(1, rrb(stack_b), 4);
		i++;
	}
}

static void	synergy(t_stack **stack_a, t_stack **stack_b, int pos)
{
	t_stack	*value;

	value = get(*stack_a, pos);
	if (value->steps_a * value->steps_b > 0)
	{
		while (value->steps_a != 0 && value->steps_b != 0)
		{
			if (value->steps_a > 0)
			{
				write(1, rr(stack_a, stack_b), 3);
				value->steps_a--;
				value->steps_b--;
			}
			else
			{
				write(1, rrr(stack_a, stack_b), 4);
				value->steps_a++;
				value->steps_b++;
			}
		}
		totalize(*stack_a);
		pos = min_steps(stack_a);
	}
	move_stack(stack_a, stack_b, pos);
}

static void	order_stacks(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b)->value != max(*stack_b))
	{
		if (get_pos(*stack_b, max(*stack_b)) <= stack_size(*stack_b) / 2)
			write(1, rb(stack_b), 3);
		else
			write(1, rrb(stack_b), 4);
	}
	sort_three(stack_a);
}

static void	zipper(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*s_a_cpy;
	int		i;

	i = 3;
	s_a_cpy = get(*stack_a, stack_size(*stack_a) - i--);
	while (stack_size(s_a_cpy) && stack_size(*stack_b))
	{
		if (max(s_a_cpy) < max(*stack_b))
			write(1, pa(stack_a, stack_b), 3);
		else
		{
			write(1, rra(stack_a), 4);
			s_a_cpy = get(*stack_a, stack_size(*stack_a) - i--);
		}
	}
	while (stack_size(*stack_b))
		write(1, pa(stack_a, stack_b), 3);
}

void	modern_times(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;

	write(1, pb(stack_a, stack_b), 3);
	write(1, pb(stack_a, stack_b), 3);
	while (stack_size(*stack_a) > 3)
	{
		count_steps_a(*stack_a);
		count_steps_b(*stack_a, *stack_b);
		totalize(*stack_a);
		pos = min_steps(stack_a);
		synergy(stack_a, stack_b, pos);
		write(1, pb(stack_a, stack_b), 3);
	}
	order_stacks(stack_a, stack_b);
	zipper(stack_a, stack_b);
}
