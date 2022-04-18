/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:19:17 by cdutel-l          #+#    #+#             */
/*   Updated: 2021/11/29 11:34:13 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_all(char **test, int i)
{
	while (i > 0)
	{
		free(test[i]);
		i--;
	}
	free (test);
	return ;
}

static int	ft_countword(char const *str, char cc)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] == cc)
			i++;
		if (str[i] && str[i] != cc)
			w++;
		while (str[i] && str[i] != cc)
			i++;
	}
	return (w);
}

static void	ft_cpyy(char *test, char *str, char cc)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] && str[i] != cc)
	{
		test[i] = str[i];
		i++;
	}
	test[i] = '\0';
}

static void	ft_countinword(char const *str, char cc, char **test)
{
	int		i;
	int		j;
	int		w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (str[i] && str[i] != cc)
		{
			j = 0;
			while (str[i + j] && str[i + j] != cc)
				j++;
			test[w] = malloc(sizeof(char) * j + 1);
			if (test[w] == 0)
				free_all(test, w);
			ft_cpyy(test[w], (char *)(str + i), cc);
			i += j;
			w++;
		}
		else
			i++;
	}
	test[w] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**test;

	k = 0;
	if (!s)
		return (NULL);
	test = NULL;
	k = ft_countword(s, c);
	test = malloc(sizeof(char *) * (k + 1));
	if (test == 0)
		return (0);
	ft_countinword(s, c, test);
	return (test);
}
