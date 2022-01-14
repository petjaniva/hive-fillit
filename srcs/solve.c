/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:41:38 by pniva             #+#    #+#             */
/*   Updated: 2022/01/14 13:28:53 by bkandemi         ###   ########.fr       */
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

void	remove_placement(t_solution *map, t_etris *mino)
{
	char	to_remove;
	char	*ptr;
	int		i;

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
