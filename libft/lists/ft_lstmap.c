/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:54:35 by achahi            #+#    #+#             */
/*   Updated: 2026/01/01 09:37:22 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*new_lst;

	if (!lst || !f)
		return (NULL);
	aux = ft_lstnew(f(lst->content));
	if (!aux)
		return (NULL);
	new_lst = aux;
	lst = lst->next;
	while (lst)
	{
		aux->next = ft_lstnew(f(lst->content));
		if (!aux->next)
		{
			if (!del)
				ft_lstdelone(lst, del);
			return (NULL);
		}
		aux = aux->next;
		lst = lst->next;
	}
	aux->next = NULL;
	return (new_lst);
}
