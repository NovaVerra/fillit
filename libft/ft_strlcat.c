/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:09:44 by nokiddy           #+#    #+#             */
/*   Updated: 2018/09/14 17:09:45 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t slen;
	size_t dlen;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dstsize <= dlen)
		return (slen + dstsize);
	while (i < dstsize - 1 && dst[i] != '\0')
		i++;
	while (src[j] != '\0' && (i + j) < (dstsize - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[j + i] = '\0';
	return (slen + dlen);
}
