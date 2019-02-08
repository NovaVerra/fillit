/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:38:50 by nokiddy           #+#    #+#             */
/*   Updated: 2018/11/06 15:38:52 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					return_index(int x, int y)
{
	return (x + (4 * y));
}

int					return_height(char *tetri_piece)
{
	int				i;
	int				min;
	int				max;

	i = 0;
	min = 3;
	max = 0;
	while (i < 16)
	{
		if (tetri_piece[i] == '#')
		{
			if (i / 4 > max)
				max = i / 4;
			if (i / 4 < min)
				min = i / 4;
		}
		i++;
	}
	return ((max - min) + 1);
}

int					return_width(char *tetri_piece)
{
	int				i;
	int				min;
	int				max;

	i = 0;
	min = 3;
	max = 0;
	while (i < 16)
	{
		if (tetri_piece[i] == '#')
		{
			if (i % 4 > max)
				max = i % 4;
			if (i % 4 < min)
				min = i % 4;
		}
		i++;
	}
	return ((max - min) + 1);
}

t_list				*delete_list(t_list *list)
{
	t_list			*delete;
	t_tetris_piece	*tetris_piece;

	delete = list;
	while (delete)
	{
		tetris_piece = (t_tetris_piece *)list->content;
		delete = list->next;
		delete_tetris_piece(tetris_piece);
		ft_memdel((void **)&list);
		list = delete;
	}
	return (NULL);
}
