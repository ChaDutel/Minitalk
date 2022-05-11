/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:38:26 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/11 11:18:21 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ifft(const char *fmt, int n, va_list args)
{
	int	i;

	i = 0;
	if (fmt[n + 1] == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (fmt[n + 1] == 's')
		i += ft_string(va_arg(args, char *));
	else if (fmt[n + 1] == '%')
		i += ft_putchar('%');
	else if (fmt[n + 1] == 'd' || fmt[n + 1] == 'i')
		ft_putnbr(va_arg(args, int), &i);
	else if (fmt[n + 1] == 'u')
		ft_unsignedputnbr(va_arg(args, unsigned int), &i);
	else if (fmt[n + 1] == 'x')
		i += ft_nbh(va_arg(args, unsigned int));
	else if (fmt[n + 1] == 'X')
		i += ft_nbhmaj(va_arg(args, int));
	else if (fmt[n + 1] == 'p')
		i += ft_pvoidh(va_arg(args, unsigned long long));
	return (i);
}
