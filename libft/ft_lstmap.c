/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:21:10 by nokiddy           #+#    #+#             */
/*   Updated: 2018/09/14 17:21:12 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*ret;

	if (!lst)
		return (NULL);
	node = (*f)(lst);
	ret = node;
	while (lst->next)
	{
		lst = lst->next;
		node->next = (*f)(lst);
		node = node->next;
	}
	return (ret);
}
