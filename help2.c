/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:03:36 by llee              #+#    #+#             */
/*   Updated: 2018/11/30 14:03:46 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				delete_board(t_board *board)
{
	int				i;

	i = board->size;
	while (i-- > 0)
		ft_memdel((void **)&board->board[i]);
	ft_memdel((void **)&board->board);
	ft_memdel((void **)&board);
}

void				delete_tetris_piece(t_tetris_piece *tetris_piece)
{
	int				i;

	i = tetris_piece->height;
	while (i-- > 0)
		ft_memdel((void **)&tetris_piece->tetri[i]);
	ft_memdel((void **)&tetris_piece->tetri);
	ft_memdel((void **)&tetris_piece);
}

t_board				*new_board(int size)
{
	t_board			*temp;
	char			**board;
	int				i;
	int				j;

	if (!(temp = (t_board *)malloc(sizeof(t_board))))
		return (NULL);
	if (!(board = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		board[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			board[i][j] = '.';
			j++;
		}
		i++;
	}
	temp->board = board;
	temp->size = size;
	return (temp);
}

t_tetris_piece		*new_piece(char **tetri, int width,
					int height, char identity)
{
	t_tetris_piece	*temp;

	if (!(temp = (t_tetris_piece *)malloc(sizeof(t_tetris_piece))))
		return (NULL);
	temp->tetri = tetri;
	temp->height = height;
	temp->width = width;
	temp->identity = identity;
	return (temp);
}
