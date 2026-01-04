/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:54:35 by achahi            #+#    #+#             */
/*   Updated: 2026/01/02 00:10:18 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				steps_a;
	int				steps_b;
	int				total;
	struct s_stack	*next;
}					t_stack;

t_stack				*copy(t_stack *stack);
void				add_new(t_stack **stack, int value);
int					compare(t_stack *lst1, t_stack *lst2);
t_stack				*get(t_stack *stack, int pos);
int					stack_size(t_stack *stack);
void				stack_print(t_stack *lst);
int					max(t_stack *stack);
int					min(t_stack *stack);
int					get_pos(t_stack *stack, int value);

char				*sa(t_stack **stack);
char				*sb(t_stack **stack);
char				*ss(t_stack **stack_a, t_stack **stack_b);
char				*pa(t_stack **stack_a, t_stack **stack_b);
char				*pb(t_stack **stack_a, t_stack **stack_b);
char				*ra(t_stack **stack_a);
char				*rb(t_stack **stack_b);
char				*rr(t_stack **stack_a, t_stack **stack_b);
char				*rra(t_stack **stack_a);
char				*rrb(t_stack **stack_b);
char				*rrr(t_stack **stack_a, t_stack **stack_b);

int					ft_issorted(t_stack *stack_a, t_stack *stack_b);
t_stack				*validator(int argc, char **argv);
void				free_stacks(t_stack **stack);

#endif