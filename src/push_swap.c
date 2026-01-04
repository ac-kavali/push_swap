/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:16:59 by achahi            #+#    #+#             */
/*   Updated: 2026/01/03 01:41:17 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = validator(argc, argv);
	stack_b = NULL;
	if (ft_issorted(stack_a, stack_b))
	{
		free_stacks(&stack_a);
		return (0);
	}
	if (argc <= 6)
	{
		short_sort(&stack_a, &stack_b);
		free_stacks(&stack_a);
	}
	else
	{
		modern_times(&stack_a, &stack_b);
		free_stacks(&stack_a);
	}
	return (0);
}
