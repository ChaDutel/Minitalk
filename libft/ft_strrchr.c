/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:33:27 by cdutel-l          #+#    #+#             */
/*   Updated: 2021/11/12 16:32:52 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	j;

	j = ft_strlen((char *)s);
	while (j != 0)
	{
		if ((unsigned char)c == (unsigned char)s[j])
			return ((char *)&s[j]);
		j--;
	}
	if ((unsigned char)s[j] == (unsigned char)c)
		return ((char *)&s[j]);
	return (0);
}
