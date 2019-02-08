/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:57:27 by nokiddy           #+#    #+#             */
/*   Updated: 2018/09/10 15:57:28 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		srcsize;
	int		i;
	char	*dest;

	srcsize = ft_strlen(s1) + 1;
	dest = (char *)malloc(srcsize * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (++i < srcsize - 1)
	{
		dest[i] = s1[i];
	}
	dest[i] = '\0';
	return (dest);
}
