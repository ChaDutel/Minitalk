/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:12:56 by cdutel-l          #+#    #+#             */
/*   Updated: 2021/11/26 16:49:12 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*str;
	t_list	*temp;

	str = lst;
	while (str)
	{
		temp = str->next;
		f(str->content);
		str = temp;
	}
	lst = NULL;
}
