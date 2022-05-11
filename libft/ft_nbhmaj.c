/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbhmaj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:33:05 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/11 11:17:04 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbhmaj(unsigned int n)
{
	char		*s;
	char		res[9];
	int			i;

	i = 0;
	s = "0123456789ABCDEF";
	while (n >= 16)
	{
		res[i] = s[n % 16];
		n = n / 16;
		i++;
	}
	res[i] = s[n % 16];
	i++;
	res[i] = '\0';
	return (ft_putstr_mod(res));
}
