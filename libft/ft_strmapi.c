/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:15:02 by nokiddy           #+#    #+#             */
/*   Updated: 2018/09/14 17:15:07 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*map;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	map = ft_strnew(len);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		map[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	return (map);
}
