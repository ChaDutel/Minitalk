/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:36:02 by cdutel-l          #+#    #+#             */
/*   Updated: 2021/11/15 17:46:20 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	j;
	char			*m;
	size_t			l;

	i = 0;
	j = start;
	l = len;
	if (!s)
		return (NULL);
	if (start > ft_strlen((char *)s))
		return (ft_calloc(sizeof(char), 1));
	if (ft_strlen((char *)s + start) < len)
		l = ft_strlen((char *)s + start);
	m = malloc(sizeof(char) * (l + 1));
	if (m == 0)
		return (NULL);
	while (i < l && s[j])
	{
		m[i] = s[j];
		i++;
		j++;
	}
	m[i] = '\0';
	return (m);
}
