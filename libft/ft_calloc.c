/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:41:53 by cdutel-l          #+#    #+#             */
/*   Updated: 2021/11/12 18:18:40 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*d;

	i = 0;
	d = malloc(size * count);
	if (!d)
		return (0);
	while (i < count * size)
	{
		d[i] = 0;
		i++;
	}
	return (d);
}
