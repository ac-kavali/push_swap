/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:47:14 by achahi            #+#    #+#             */
/*   Updated: 2026/01/03 02:21:56 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	no_repeating_values(t_stack *stack_a, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (get(stack_a, i)->value == get(stack_a, j)->value)
			{
				free_stacks(&stack_a);
				exit_error();
			}
			j++;
		}
		i++;
	}
}

static t_stack	*create_stack(char **numbers, char *lst)
{
	t_stack		*stack_a;
	int			i;
	long long	aux;

	stack_a = NULL;
	i = 0;
	while (numbers[i] != NULL)
	{
		aux = ft_atoi_safe(numbers[i]);
		if (aux > 2147483647 || aux < -2147483648)
		{
			free_stacks(&stack_a);
			fexit_error(lst, NULL, numbers);
		}
		add_new(&stack_a, (int)aux);
		i++;
	}
	free_matrix(numbers);
	return (stack_a);
}

static char	*parser(char **val)
{
	int		i;
	int		j;
	char	*lst;

	if (!*val)
		return (free_matrix(val), NULL);
	i = 0;
	lst = ft_strdup("");
	while (val[i] != NULL)
	{
		j = 0;
		if ((val[i][0] == '-' || val[i][0] == '+') && ft_strlen(val[i]) > 1)
			j++;
		while (val[i][j] != '\0')
		{
			if (!ft_isdigit(val[i][j]))
				return (free(lst), free_matrix(val), NULL);
			j++;
		}
		lst = ft_fstrjoin(ft_fstrjoin(lst, val[i++]), " ");
		if (!lst)
			return (free(lst), NULL);
	}
	free_matrix(val);
	return (lst);
}

t_stack	*validator(int argc, char **argv)
{
	char	*parsed;
	char	*lst;
	t_stack	*stack_a;
	int		i;

	if (argc <= 1)
		return (NULL);
	lst = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		if (!ft_strlen(argv[i]))
			fexit_error(lst, NULL, NULL);
		parsed = parser(ft_split(argv[i++], ' '));
		if (!parsed)
			fexit_error(lst, parsed, NULL);
		lst = ft_fstrjoin(lst, parsed);
		if (!lst)
			fexit_error(lst, parsed, NULL);
		free(parsed);
	}
	stack_a = create_stack(ft_split(lst, ' '), lst);
	free(lst);
	no_repeating_values(stack_a, stack_size(stack_a));
	return (stack_a);
}
