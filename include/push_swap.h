/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:54:35 by achahi            #+#    #+#             */
/*   Updated: 2026/01/02 17:14:27 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

void	exit_error(void);
void	fexit_error(char *s1, char *s2, char **matrix);
void	short_sort(t_stack **stack_a, t_stack **stack_b);
void	modern_times(t_stack **stack_a, t_stack **stack_b);
void	count_steps_a(t_stack *stack_a);
void	count_steps_b(t_stack *stack_a, t_stack *stack_b);
void	totalize(t_stack *stack_a);
int		min_steps(t_stack **stack_a);
void	bring_to_top(t_stack **stack, int value);
int		get_min(t_stack *stack);
void	sort_three(t_stack **a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);

#endif