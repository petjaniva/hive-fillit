/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:41:38 by pniva             #+#    #+#             */
/*   Updated: 2022/01/12 13:39:07 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_solution	*solve(t_etris *tetri_first)
{
	t_solution	*map;

	map = initiate_map(*tetri_first);
	if (!map)
		return (NULL);
	while (!find_solution(map, tetri_first))
	{
		grow_board(map);
	}
	return (map);
}

t_solution	*initiate_map(t_etris tetri_first)
{
	int			minos_count;
	t_solution	*map;
	int			min_board_size;
	int			i;

	i = 0;
	map = malloc(sizeof(*map));
	if (!map)
		return (NULL);
	minos_count = count_minos(&tetri_first);
	min_board_size = sqrt_up(minos_count * 4);
	map->height = min_board_size;
	map->board = strnewarray(min_board_size, min_board_size);
	while (i < min_board_size)
	{
		ft_memset(map->board[i], '.', min_board_size);
		++i;
	}
	if (!check_if_mino_fit(min_board_size, &tetri_first))
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
//TODO replace move_mino with a function that looks for empty square and
//then checks if the current mino can fit there
int	find_solution(t_solution *map, t_etris *mino)
{
	if (!mino)
		return (TRUE);
	while (find_place_for_mino(map, mino))
	{
		if (find_solution(map, mino->next))
				return (TRUE);
	}
	remove_placement(map, mino);
	//need to increment offsets
	return (FALSE);
}

int	find_place_for_mino(t_solution *map, t_etris *mino)
{
	char	*empty;
	size_t	i;

	i = mino->y_offset;
	while (i < map->height)
	{
		
		empty = ft_strchr(&map->board[i][mino->x_offset], '.');
		while (empty)
		{
			mino->y_offset = i;
			mino->x_offset = empty - map->board[i];
			if (try_placing_mino(map, mino))
			{
				place_mino(map, mino);
				return (TRUE);
			}
			empty = ft_strchr(empty + 1, '.');
		}
		mino->x_offset = 0;
		++i;
	}
	return (FALSE);
}

int	try_placing_mino(t_solution *map, t_etris *mino)
{
	if (mino_in_bounds(map, mino))
	{
		if (!is_there_overlap(map, mino))
			return (TRUE);
	}
	return (FALSE);
}

int	mino_in_bounds(t_solution *map, t_etris *mino)
{
	size_t	y_max;
	size_t	x_max;

	y_max = mino->y_offset + mino->height;
	x_max = mino->x_offset + mino->width;
	if (y_max >= map->height || x_max >= map->height)
		return (FALSE);
	else
		return (TRUE);
}

void	remove_placement(t_solution *map, t_etris *mino)
{
	char	to_remove;
	char	*ptr;
	size_t	i;

	to_remove = mino->c - 1;
	i = 0;
	while (i < map->height)
	{
		ptr = ft_strchr(map->board[i], to_remove);
		while (ptr)
		{
			*ptr = '.';
			ptr = ft_strchr(map->board[i], to_remove);
		}
		++i;
	}
}

int	is_there_overlap(t_solution *map, t_etris *mino)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	while (i < 8)
	{
		y = mino->y_offset + mino->coordinates[i++];
		x = mino->x_offset + mino->coordinates[i++];
		if (check_overlap(map, y, x))
			return (TRUE);
	}
	return (FALSE);
}

int	check_overlap(t_solution *map, int y, int x)
{
	if (map->board[y][x] != '.')
		return (TRUE);
	else
		return (FALSE);
}

void	place_mino(t_solution *map, t_etris *mino)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	while (i < 8)
	{
		y = mino->y_offset + mino->coordinates[i++];
		x = mino->x_offset + mino->coordinates[i++];
		map->board[y][x] = mino->c;
	}
}

t_solution	*grow_board(t_solution *map)
{
	size_t	new_height;
	size_t	i;

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
