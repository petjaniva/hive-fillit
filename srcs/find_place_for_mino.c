/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place_for_mino.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:25:35 by bkandemi          #+#    #+#             */
/*   Updated: 2022/01/14 13:28:16 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

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
