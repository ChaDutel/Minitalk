/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:31:02 by cdutel-l          #+#    #+#             */
/*   Updated: 2021/11/12 13:04:30 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lensrc;

	i = ft_strlen(dst);
	lensrc = ft_strlen((char *)src);
	if (dstsize == 0 || dstsize < i)
		return (dstsize + lensrc);
	j = 0;
	while ((i + j) < dstsize - 1 && src[j])
	{
		dst[i + j] = src[j];
		j ++;
	}
	dst[i + j] = '\0';
	return (i + lensrc);
}
/*
 int	main(void)
{
	char	s[100] = "le ciel est bleu";
	char	l[] = "et il fait beau";

	printf("%zu", ft_strlcat(s, l, ft_strlen(s) + ft_strlen(l)));
} */