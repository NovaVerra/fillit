/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:05:12 by llee              #+#    #+#             */
/*   Updated: 2018/11/30 14:05:18 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris_piece		*valid_tetrimino(char *buf, char identity)
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if ((i + 1) < 20 && buf[i + 1] == '#')
				valid++;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				valid++;
			if ((i + 5) < 20 && buf[i + 5] == '#')
				valid++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				valid++;
		}
		i++;
	}
	return (create_tetri(buf, valid, identity));
}

int					valid_file(char *buf, int byte_count)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(buf[i] != '.' || buf[i] != '#'))
				return (0);
			if (buf[i] == '#')
				count++;
		}
		else if (buf[i] != '\n')
			return (0);
		i++;
	}
	if (byte_count == 21 && buf[20] != '\n')
		return (0);
	if (count != 4)
		return (0);
	return (1);
}

t_list				*get_tetriminos(int fd, t_list *list)
{
	char			*buf;
	char			identity;
	t_tetris_piece	*tetri_map;
	int				retval;
	int				prev;

	identity = 'A';
	buf = ft_strnew(21);
	list = NULL;
	while ((retval = read(fd, buf, 21)) >= 20)
	{
		if (valid_file(buf, retval) == 0 || (tetri_map =
		valid_tetrimino(buf, identity++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (delete_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetri_map, sizeof(t_tetris_piece)));
		ft_memdel((void **)&tetri_map);
		prev = retval;
	}
	ft_memdel((void **)&buf);
	if (prev == 21 || retval != 0 || identity == 'B')
		return (delete_list(list));
	return (list);
}
