/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pvoidh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:33:30 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/11 11:17:51 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pvoidh(unsigned long long n)
{
	char		*s;
	char		res[20];
	int			i;

	s = "0123456789abcdef";
	i = 0;
	while (n >= 16)
	{
		res[i] = s[n % 16];
		n = n / 16;
		i++;
	}
	res[i] = s[n % 16];
	i++;
	res[i] = '\0';
	ft_putstr_mod("x0");
	return (ft_putstr_mod2(res));
}
