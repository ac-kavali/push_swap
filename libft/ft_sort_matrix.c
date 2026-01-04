/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:54:35 by achahi            #+#    #+#             */
/*   Updated: 2026/01/01 09:38:29 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_matrix_size(char **env)
{
	int	count;

	count = 0;
	while (*env)
	{
		count++;
		env++;
	}
	return (count);
}

char	**ft_sort_matrix(char **mat)
{
	int		i;
	int		j;
	int		len;
	char	*aux;

	i = 0;
	len = ft_get_matrix_size(mat);
	while (i < len)
	{
		j = -1;
		while (++j < (len - i - 1))
		{
			aux = mat[j];
			if (ft_strcmp(mat[j], mat[j + 1]) > 0)
			{
				aux = mat[j];
				mat[j] = mat[j + 1];
				mat[j + 1] = aux;
			}
		}
		i++;
	}
	return (mat);
}
