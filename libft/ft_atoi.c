/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:11:21 by nokiddy           #+#    #+#             */
/*   Updated: 2018/09/14 17:11:23 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] && (str[i] >= '\t' && str[i] <= '\r')) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = -2 * (str[i] == '-') + 1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + str[i++] - '0';
	return ((int)result * sign);
}
