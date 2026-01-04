/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:54:35 by achahi            #+#    #+#             */
/*   Updated: 2026/01/01 09:36:53 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_new(t_list **list, void *context)
{
	t_list	*new_node;

	new_node = ft_lstnew(context);
	if (!*list)
		*list = new_node;
	else
		ft_lstadd_back(list, new_node);
}
