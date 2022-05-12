/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:36:33 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/12 14:55:40 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*ft_strjoinmini(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*str;
	int		lenght;

	i = 0;
	k = 0;
	if (!s1)
	{
		lenght = ft_strlen((char *)s2);
		str = malloc(sizeof(char) * (lenght + 1));
		if (!str)
			return (NULL);
			str[0] = s2[0];
		return (str);
	}
	lenght = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	str = malloc(sizeof(char) * (lenght + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i ++;
	}
	while (s2[k])
	{
		str[i++] = s2[k++];
	}
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
	{
		tab[i] = 0;
		i++;
	}
	else
	{
		tab[i] = 1;
		i++;
	}
	if (i == 8)
	{
		i = 0;
		result = ft_byte_to_dec(tab);
		str = ft_strjoinmini(str, &result);
		ft_printf("%s\n", str);
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

/* char	ft_byte_to_dec(int *resbytes)
{
	int		i;
	char	letter;
	//int		total;
	i = 1;
	//letter = malloc(sizeof(char) * 8 + 1);
	while (i < 8)
	{
		//i = i + resbytes[i] * 2 ^ i;
		letter = letter + resbytes[i] * ft_iterative_power(2, i);
		i++;
	}
	return (letter);
} */


/* char	ft_byte_to_dec(int *resbytes)
{
	int		i;
	char	letter;
	//int		total;
	i = 0;
	letter = 0;
	//letter = malloc(sizeof(char) * 8 + 1);
	while (i < 8)
	{
		//i = i + resbytes[i] * 2 ^ i;
		letter = letter + resbytes[i] * ft_iterative_power(2, i);
		i++;
	}
	//letter -= 9;
	return (letter);
}

void	handler(int signum)
{
	char	result;
	//int		addbyte;
	static int	i = 0;
	static int	tab[8];
	int			u;

	//addbyte = 0;
	u = 0;
	if (signum == SIGUSR1)
	{
		//addbyte = addbyte * 10;
		tab[i] = 0;
		i++;
		//ft_printf("0\n");
	}
	else
	{
		//ft_printf("1\n");
		//addbyte = addbyte * 10 + 1;
		tab[i] = 1;
		i++;
	}
	if (i == 8)
	{
		while (u < 8)
		{
			ft_printf("%d\n", tab[u]);
			u++;
		}
		i = 0;
		result = ft_byte_to_dec(tab);
		ft_printf("%c\n", result);
	}
} */