/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:21:27 by pniva             #+#    #+#             */
/*   Updated: 2022/01/13 10:28:10 by pniva            ###   ########.fr       */
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
	if (!check_if_mino_fit(min_board_size, tetri_first))
		grow_board(map);
	return (map);
}

int	check_if_mino_fit(int min_board_size, t_etris *tetri_first)
{
	t_etris	*mino;

	mino = tetri_first;
	while (mino)
	{
		if (mino->height >= min_board_size
			|| mino->width >= min_board_size)
			return (FALSE);
		mino = mino->next;
	}
	return (TRUE);
}

void	create_origin_coords(t_etris *mino)
{
	int	num;
	int	i;

	i = 0;
	if (mino->coordinates[0] != 0)
	{
		num = mino->coordinates[0];
		while (i < 8)
		{
			if (i % 2 == 0)
				mino->coord_origin[i] = mino->coordinates[i] - num;
			else
				mino->coord_origin[i] = mino->coordinates[i];
			++i;
		}
	}
	else if (mino->coordinates[1] != 0)
	{
		num = mino->coordinates[1];
		while (i < 8)
		{
			if (i % 2 != 0)
				mino->coord_origin[i] = mino->coordinates[i] - num;
			else
				mino->coord_origin[i] = mino->coordinates[i];
			++i;
		}
	}
	else
		ft_memcpy(mino->coord_origin, mino->coordinates, sizeof(int) * 8);
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
