/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:36:33 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/12 18:43:45 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/* char	*if_no_s_one(char *s2)
{
	int		lenght;
	char	*str;

	lenght = ft_strlen((char *)s2);
	str = malloc(sizeof(char) * (lenght + 1));
	if (!str)
		return (NULL);
	str[0] = s2[0];
	return (str);
	
	
	return (if_no_s_one(s2));
} */

char	*ft_strjoinmini(char *s1, char c)
{
	int		i;
	char	*str;

	i = 0;
	if (!s1)
	{
		str = malloc(sizeof(char) + 1);
		if (!str)
			return (NULL);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (ft_strlen((char *)s1 + 2)));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power != 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

char	ft_byte_to_dec(int *resbytes)
{
	int		i;
	char	letter;

	i = 0;
	letter = 0;
	while (i < 8)
	{
		letter = letter + resbytes[i] * ft_iterative_power(2, i);
		i++;
	}
	return (letter);
}

void	handler(int signum)
{
	char			result;
	static char		*str = NULL;
	static int		i = 0;
	static int		tab[8];

	if (signum == SIGUSR1)
		tab[i] = 0;
	else
		tab[i] = 1;
	i++;
	if (i == 8)
	{
		i = 0;
		result = ft_byte_to_dec(tab);
		if (result == '\0')
		{
			ft_printf("%s", str);
			free(str);
			str = NULL;
		}
		str = ft_strjoinmini(str, result);
	}
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
