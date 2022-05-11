/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:03:16 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/11 11:17:11 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		n;

	va_start(args, fmt);
	i = 0;
	n = 0;
	while (fmt[n] != '\0')
	{
		if (fmt[n] == '%' && fmt[n + 1])
		{
			i += ft_ifft(fmt, n, args);
			n++;
		}
		else
		{
			write (1, &fmt[n], 1);
			i++;
		}
		n++;
	}
	va_end(args);
	return (i);
}
