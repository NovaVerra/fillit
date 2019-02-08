/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:17:05 by nokiddy           #+#    #+#             */
/*   Updated: 2018/09/14 17:17:07 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_whitespace(char c)
{
	if (c == '\r' || c == '\t' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (ft_is_whitespace(s[i]))
		i++;
	while (ft_is_whitespace(s[j - 1]))
		j--;
	if (j < i)
		j = i;
	trim = ft_strnew(j - i);
	if (trim == NULL)
		return (NULL);
	return (ft_strncpy(trim, s + i, j - i));
}
