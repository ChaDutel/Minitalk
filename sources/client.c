/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:36:23 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/11 12:28:45 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_sendsig(int pid, char *str)
{
	if (str[0] == '0')
		kill(pid, SIGUSR1);
	if (str[0] == '1')
		kill(pid, SIGUSR2);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	ft_sendsig(ft_atoi(argv[1]), argv[2]);
	return (0);
}
