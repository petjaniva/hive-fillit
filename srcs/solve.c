/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:41:38 by pniva             #+#    #+#             */
/*   Updated: 2022/01/13 10:28:13 by pniva            ###   ########.fr       */
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

int	find_place_for_mino(t_solution *map, t_etris *mino)
{
	char	*empty;
	int		i;

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
