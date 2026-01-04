/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahi <achahi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:54:35 by achahi            #+#    #+#             */
/*   Updated: 2026/01/01 09:40:05 by achahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len_s;
	char	*str;

	str = (char *)s;
	len_s = ft_strlen(str);
	while (len_s >= 0)
	{
		if (str[len_s] == (unsigned char)c)
			return (&str[len_s]);
		len_s--;
	}
	return (0);
}
