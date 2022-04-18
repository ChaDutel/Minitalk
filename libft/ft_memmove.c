/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:22:41 by cdutel-l          #+#    #+#             */
/*   Updated: 2021/11/12 14:59:42 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ft(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*g;

	i = 0;
	g = (const char *)src;
	while (i != len && dst < src)
	{
		((char *)dst)[i] = g[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*g;

	g = (const char *)src;
	i = 0;
	if (!dst && !src)
		return (dst);
	if (i < len && dst < src)
	{
		ft_ft(dst, src, len);
	}
	if (i < len && dst > src)
	{
		i = len - 1;
		while (i > 0)
		{
			((char *)dst)[i] = g[i];
			i--;
		}
		((char *)dst)[i] = g[i];
	}
	return (dst);
}
