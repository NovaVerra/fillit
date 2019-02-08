/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:03:08 by llee              #+#    #+#             */
/*   Updated: 2018/11/30 12:03:13 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display_board(t_board *board)
{
	int x;

	x = 0;
	while (x < board->size)
	{
		ft_putstr(board->board[x]);
		ft_putchar('\n');
		x++;
	}
}

void	print_error_bye_bye(int error)
{
	if (error == 0)
		write(1, "usage: ./fillit source_file\n", 29);
	else
		write(1, "error\n", 6);
	exit(0);
}

void	clean_up_leaks(t_list *list, t_board *board)
{
	delete_list(list);
	delete_board(board);
}

int		main(int argc, char **argv)
{
	t_list	*tetriminos;
	t_list	*temp;
	t_board	*board;

	temp = NULL;
	if (argc != 2)
		print_error_bye_bye(0);
	if ((tetriminos = get_tetriminos(open(argv[1], O_RDONLY), temp)) == NULL)
		print_error_bye_bye(1);
	if ((board = add_tetriminos(tetriminos)) == NULL)
		print_error_bye_bye(2);
	display_board(board);
	clean_up_leaks(tetriminos, board);
	return (0);
}
