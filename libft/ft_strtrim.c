/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:23:43 by cdutel-l          #+#    #+#             */
/*   Updated: 2021/11/29 11:34:58 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ftfind(const char	*s, const char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			l;
	char		*c;
	int			h;

	i = 0;
	l = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_ftfind(set, s1[i]) == 1)
		i++;
	while (s1[l])
		l++;
	while (l >= 0 && ft_ftfind(set, s1[l]) == 1)
		l--;
	h = l - i + 1;
	if (l == -1)
		return (ft_calloc(1, 1));
	c = malloc(sizeof(char) * h + 1);
	if (!c)
		return (NULL);
	ft_strlcpy(c, &s1[i], h + 1);
	return (c);
}
