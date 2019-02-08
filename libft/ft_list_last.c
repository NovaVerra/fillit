/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 12:08:53 by nokiddy           #+#    #+#             */
/*   Updated: 2018/07/03 12:08:56 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_last(t_list *begin_list)
{
	t_list *list;

	list = begin_list;
	if (!list)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}
