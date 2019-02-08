/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 12:28:58 by nokiddy           #+#    #+#             */
/*   Updated: 2018/07/03 12:29:00 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	t_list	*next;
	int		i;

	i = 0;
	if (ac < 1)
		return (0);
	next = 0;
	while (i < ac)
	{
		list = ft_create_elem(av[i]);
		list->next = next;
		next = list;
		i++;
	}
	return (list);
}
