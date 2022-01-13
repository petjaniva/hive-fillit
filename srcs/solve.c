/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:41:38 by pniva             #+#    #+#             */
/*   Updated: 2022/01/13 11:27:10 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_solution	*solve(t_etris *tetri_first)
{
	t_solution	*map;

	map = initiate_map(tetri_first);
	if (!map)
		return (NULL);
	while (!find_solution(map, tetri_first))
	{
		grow_board(map);
	}
	return (map);
}

int	find_solution(t_solution *map, t_etris *mino)
{
	if (!mino)
		return (TRUE);
	create_origin_coords(mino);
	while (find_place_for_mino(map, mino))
	{
		place_mino(map, mino);
		if (find_solution(map, mino->next))
				return (TRUE);
		remove_placement(map, mino);
		increment_offsets(map, mino);
	}
	mino->x_offset = 0;
	mino->y_offset = 0;
	return (FALSE);
}

/* Tries to find an empty spot on the board where the mino
   fits without going out of bounds or overlapping other 
   minos*/

int	find_place_for_mino(t_solution *map, t_etris *mino)
{
	char	*empty_spot;
	int		row;

	row = mino->y_offset;
	while (row < map->height)
	{
		
		empty_spot = ft_strchr(&map->board[row][mino->x_offset], '.');
		while (empty_spot)
		{
			mino->y_offset = row;
			mino->x_offset = empty_spot - map->board[row];
			if (try_placing_mino(map, mino))
			{
				return (TRUE);
			}
			empty_spot = ft_strchr(empty_spot + 1, '.');
		}
		mino->x_offset = 0;
		++row;
	}
	return (FALSE);
}
/* Tries to place mino with the calculated offsets by checking 
   if the mino is in bounds and doesn't overlap with other minos*/

int	try_placing_mino(t_solution *map, t_etris *mino)
{
	if (mino_in_bounds(map, mino))
	{
		if (!is_there_overlap(map, mino))
			return (TRUE);
	}
	return (FALSE);
}
/* Retuns TRUE if none of minos 4 spots go over the squares
   dimensions */
int	mino_in_bounds(t_solution *map, t_etris *mino)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	while (i < 8)
	{
		y = mino->y_offset + mino->coord_origin[i++];
		x = mino->x_offset + mino->coord_origin[i++];
		if (y < 0 || x < 0 || y >= map->height || x >= map->height)
			return (FALSE);
	}
	return (TRUE);
}

void	remove_placement(t_solution *map, t_etris *mino)
{
	char	to_remove;
	char	*ptr;
	int	i;

	to_remove = mino->c;
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
		y = mino->y_offset + mino->coord_origin[i++];
		x = mino->x_offset + mino->coord_origin[i++];
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
		y = mino->y_offset + mino->coord_origin[i++];
		x = mino->x_offset + mino->coord_origin[i++];
		map->board[y][x] = mino->c;
	}
}
