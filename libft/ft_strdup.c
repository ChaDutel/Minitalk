/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:21:57 by cdutel-l          #+#    #+#             */
/*   Updated: 2021/11/13 12:25:39 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s;
	int		h;

	i = 0;
	h = ft_strlen((char *)s1) + 1;
	s = malloc(ft_strlen((char *)s1) + 1);
	if (s == 0)
		return (0);
	while (s1[i])
	{
		s[i] = ((char *)s1)[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
