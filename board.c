/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:19:17 by llee              #+#    #+#             */
/*   Updated: 2018/11/30 12:19:19 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					check(t_tetris_piece *tetri_piece,
					t_board *board, int pos_x, int pos_y)
{
	int				i;
	int				j;
	int				pos_array[2];

	i = 0;
	while (i < tetri_piece->width)
	{
		j = 0;
		while (j < tetri_piece->height)
		{
			if (tetri_piece->tetri[j][i] == '#' &&
			board->board[pos_y + j][pos_x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	pos_array[0] = pos_x;
	pos_array[1] = pos_y;
	place(tetri_piece, board, pos_array, tetri_piece->identity);
	return (1);
}

void				place(t_tetris_piece *tetri_piece, t_board *board,
					int *pos_array, char identity)
{
	int				i;
	int				j;

	i = 0;
	while (i < tetri_piece->width)
	{
		j = 0;
		while (j < tetri_piece->height)
		{
			if (tetri_piece->tetri[j][i] == '#')
				board->board[pos_array[1] + j][pos_array[0] + i] = identity;
			j++;
		}
		i++;
	}
}

int					adding(t_list *tetriminos, t_board *board)
{
	t_tetris_piece	*tetris_piece;
	int				pos_x;
	int				pos_y;
	int				pos_array[2];

	pos_y = -1;
	if (tetriminos == NULL || (tetris_piece =
	(t_tetris_piece *)tetriminos->content) == NULL)
		return (1);
	while (++pos_y < board->size - tetris_piece->height + 1)
	{
		pos_x = -1;
		while (++pos_x < board->size - tetris_piece->width + 1)
		{
			if (check(tetris_piece, board, pos_x, pos_y))
			{
				if (adding(tetriminos->next, board))
					return (1);
				pos_array[0] = pos_x;
				pos_array[1] = pos_y;
				place(tetris_piece, board, pos_array, '.');
			}
		}
	}
	return (0);
}

int					find_closest_square(int size)
{
	int				n;

	n = 2;
	while (n * n < size)
		n++;
	return (n);
}

t_board				*add_tetriminos(t_list *tetriminos)
{
	int				size;
	t_board			*board;

	ft_list_reverse(&tetriminos);
	size = find_closest_square(ft_list_size(tetriminos) * 4);
	board = new_board(size);
	while (!adding(tetriminos, board))
	{
		delete_board(board);
		size++;
		board = new_board(size);
	}
	return (board);
}
