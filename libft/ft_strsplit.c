/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:17:19 by nokiddy           #+#    #+#             */
/*   Updated: 2018/09/14 17:17:20 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(const char *str, char c)
{
	int			i;
	int			wordcount;
	int			word;

	i = 0;
	wordcount = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != c && str[i])
		{
			i++;
			word = 1;
		}
		if (str[i] == c || !(str[i]))
		{
			if (word)
				wordcount++;
			i++;
			word = 0;
		}
	}
	return (wordcount);
}

static int		word_len(const char *str, char c, int position)
{
	int			length;

	length = 1;
	if (!str)
		return (0);
	while (str[position] != c && str[position])
	{
		position++;
		length++;
	}
	return (length);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**temp;
	int			i;
	int			j;
	int			wordlength;

	i = 0;
	j = 0;
	if (!(temp = malloc((word_count(s, c) + 1) * sizeof(char *))) || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			wordlength = 0;
			if (!(temp[j] = malloc((word_len(s, c, i) + 1) * sizeof(char))))
				return (NULL);
			while (s[i] != c && s[i])
				temp[j][wordlength++] = s[i++];
			temp[j++][wordlength] = '\0';
		}
	}
	temp[j] = NULL;
	return (temp);
}
