/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:55:07 by nokiddy           #+#    #+#             */
/*   Updated: 2018/11/06 14:55:10 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					find_offset(char *tetri, int index)
{
	int				min_width;
	int				min_height;
	int				i;

	min_width = 3;
	min_height = 3;
	i = 0;
	while (i < 16)
	{
		if (tetri[i] == '#')
		{
			if (i / 4 < min_height)
				min_height = i / 4;
			if (i % 4 < min_width)
				min_width = i % 4;
		}
		i++;
	}
	return (min_width + (min_height + index) * 4);
}

t_tetris_piece		*make_it_2d(char *tetri, char identity)
{
	char			**temp;
	int				height;
	int				width;
	int				i;
	t_tetris_piece	*tetri_piece;

	height = return_height(tetri);
	width = return_width(tetri);
	temp = (char **)malloc(sizeof(char *) * height);
	i = 0;
	while (i < height)
	{
		temp[i] = ft_strnew(width);
		ft_strncpy(temp[i], tetri + find_offset(tetri, i), width);
		i++;
	}
	tetri_piece = new_piece(temp, width, height, identity);
	return (tetri_piece);
}

t_tetris_piece		*create_tetri(char *buf, int valid, char identity)
{
	char			*tetri;
	int				i;
	int				j;

	if (!(valid == 6 || valid == 8))
		return (NULL);
	tetri = ft_strnew(17);
	i = 0;
	j = 0;
	while (i < 20)
	{
		if (buf[i] == '.' || buf[i] == '#')
			tetri[j++] = buf[i];
		i++;
	}
	tetri[j] = '\0';
	return (make_it_2d(tetri, identity));
}
