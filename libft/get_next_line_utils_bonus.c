/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:56:48 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/11 11:11:01 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	if (s[i] && s[i] == c)
		return (1);
	return (0);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*c;

	i = 0;
	k = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	c = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[k])
		c[i++] = s2[k++];
	c[ft_strlen_gnl(s1) + ft_strlen_gnl(s2)] = '\0';
	free (s1);
	return (c);
}
