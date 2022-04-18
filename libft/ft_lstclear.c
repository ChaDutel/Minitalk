/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:40:55 by cdutel-l          #+#    #+#             */
/*   Updated: 2021/11/26 16:09:50 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*str;
	t_list	*temp;

	str = *lst;
	while (str)
	{
		temp = str->next;
		ft_lstdelone(str, del);
		str = temp;
	}
	*lst = NULL;
}
