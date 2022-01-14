/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:21:27 by pniva             #+#    #+#             */
/*   Updated: 2022/01/14 14:13:04 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_solution	*initiate_map(t_etris *tetri_first)
{
	int			minos_count;
	t_solution	*map;
	int			min_board_size;
	int			i;

	i = 0;
	map = malloc(sizeof(*map));
	if (!map)
		return (NULL);
	minos_count = count_minos(tetri_first);
	min_board_size = sqrt_up(minos_count * 4);
	map->height = min_board_size;
	map->board = strnewarray(min_board_size, min_board_size);
	while (i < min_board_size)
	{
		ft_memset(map->board[i], '.', min_board_size);
		++i;
	}
	return (map);
}

int	count_minos(t_etris *tetri_first)
{
	int		minos_count;
	t_etris	*mino;

	minos_count = 0;
	mino = tetri_first;
	while (mino)
	{
		minos_count++;
		mino = mino->next;
	}
	return (minos_count);
}

void	increment_offsets(t_solution *map, t_etris *mino)
{
	if (mino->x_offset >= map->height)
	{
		mino->y_offset++;
		mino->x_offset = 0;
	}
	else
		mino->x_offset++;
}

t_solution	*grow_board(t_solution *map)
{
	int	new_height;
	int	i;

	new_height = map->height + 1;
	i = 0;
	ft_free_ptr_array((void **)map->board, map->height);
	map->board = malloc(sizeof(*(map->board)) * new_height);
	if (!map->board)
		return (NULL);
	while (i < new_height)
	{
		map->board[i] = ft_strnew(new_height);
		ft_memset(map->board[i], '.', new_height);
		++i;
	}
	map->height = new_height;
	return (map);
}
