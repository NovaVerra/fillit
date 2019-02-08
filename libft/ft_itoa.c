/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:17:36 by nokiddy           #+#    #+#             */
/*   Updated: 2018/09/14 17:17:38 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_digits(long n)
{
	size_t i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*num;
	size_t	i;
	long	temp;
	char	sign;

	temp = n;
	sign = (temp < 0 ? 1 : 0);
	i = ft_num_digits(temp);
	num = ft_strnew(i + sign);
	if (!num)
		return (NULL);
	if (sign)
	{
		temp = -temp;
		num[0] = '-';
	}
	while (i > 0)
	{
		num[i + sign - 1] = (temp % 10) + '0';
		i--;
		temp = temp / 10;
	}
	return (num);
}
