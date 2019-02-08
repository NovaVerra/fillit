/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 12:53:21 by nokiddy           #+#    #+#             */
/*   Updated: 2018/07/03 12:53:23 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*temp;

	i = 0;
	temp = begin_list;
	while (temp)
	{
		if (i == nbr)
			return (temp);
		i++;
		temp = temp->next;
	}
	return (0);
}
