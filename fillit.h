/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:11:21 by llee              #+#    #+#             */
/*   Updated: 2018/11/30 12:11:25 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 1024
# define VALID_CHECK(x) if (x == NULL || x < 0) return (-1);

# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_board
{
	char		**board;
	int			size;
}				t_board;

typedef struct	s_tetris_piece
{
	char		**tetri;
	int			height;
	int			width;
	char		identity;
}				t_tetris_piece;

int				return_height(char *tetri_piece);
int				return_width(char *tetri_piece);
t_board			*add_tetriminos(t_list *tetriminos);
t_list			*get_tetriminos(int fd, t_list *list);
int				valid_file(char *buf, int byte_count);
t_tetris_piece	*valid_tetrimino(char *buf, char identity);
t_list			*delete_list(t_list *list);
void			clean_up_leaks(t_list *list, t_board *board);
void			display_board(t_board *board);
t_tetris_piece	*create_tetri(char *buf, int valid, char identity);
t_board			*new_board(int size);
void			delete_board(t_board *board);
int				check(t_tetris_piece *tetri_piece,
				t_board *board, int pos_x, int pos_y);
void			place(t_tetris_piece *tetri_piece,
				t_board *board, int *pos_array, char identity);
int				adding(t_list *tetriminos, t_board *board);
int				find_closest_square(int size);
void			find_dimensions(const char **tetri_piece,
				int *dimensions);
int				find_offset(char *tetri, int index);
t_tetris_piece	*new_piece(char **tetri, int width,
				int height, char identity);
void			delete_tetris_piece(t_tetris_piece *tetris_piece);
#endif
