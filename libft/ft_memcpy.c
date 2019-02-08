/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:07:56 by nokiddy           #+#    #+#             */
/*   Updated: 2018/09/14 17:07:58 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n > 0)
	{
		n--;
		((unsigned char*)dst)[n] = ((unsigned char*)src)[n];
	}
	return (dst);
}
