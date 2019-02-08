/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:23:12 by nokiddy           #+#    #+#             */
/*   Updated: 2018/07/03 11:23:14 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*last;

	new = ft_create_elem(data);
	last = *begin_list;
	if (!last)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}
