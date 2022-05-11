/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:36:33 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/11 20:11:15 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	ft_byte_to_dec(int resbytes)
{
	h
}
 
void	handler(int signum)
{
	char	result;
	int		addbyte;
	int		i;
	int		tab[8];

	addbyte = 0;
	i = 0;
	if (signum == SIGUSR1)
	{
		addbyte = addbyte * 10;
		tab[i] = 0;
		i++;
		//ft_printf("0\n");
	}
	else
	{
		//ft_printf("1\n");
		addbyte = addbyte * 10 + 1;
		tab[i] = 1;
		i++;
	}
	//result = ft_byte_to_dec(tab);
	ft_printf("%s\n", result);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	if (pid == 0)
	{
		ft_printf("error\n");
		return (0);
	}
	ft_printf("%d\n", pid);
	action.sa_handler = handler;
	action.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
	}
}

/* int	i;

	i = 0;
	if (signum == SIGUSR1)
		ft_printf("0\n");
	else
		ft_printf("1\n"); */

/*void	handler(int signum)
{
	//static int	valfirst;
	//static int	valsecond;
	int	result;
	int	i;

	i = 0;
	result = 0;
	if (signum == SIGUSR1)
	{
		result = result * 10;
		//ft_printf("0\n");
	}
	else
		//ft_printf("1\n");
		result = result * 10 + 1;
	//i = ft_byte_to_dec(result);
	ft_printf("%d\n", result);
} */

/* void	handler(int signum)
{
	char	*result;
	int		addbyte;

	addbyte = 0;
	if (signum == SIGUSR1)
	{
		addbyte = addbyte * 10;
		//ft_printf("0\n");
	}
	else
		//ft_printf("1\n");
		addbyte = addbyte * 10 + 1;
	result = ft_byte_to_dec(addbyte);
	ft_printf("%s\n", result);
} */