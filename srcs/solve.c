/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:41:38 by pniva             #+#    #+#             */
/*   Updated: 2022/01/11 07:16:11 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_solution	*solve(t_etris *tetri_first)
{
	t_solution	*solution;
	t_etris		*tetrimino;

	solution = intiate_solution(tetri_first);
	while (!find_solution(solution, tetri_first))
	{
		grow_solution(solution);
	}
	return (solution);
}

t_solution	*initiate_solution(t_etris tetri_first)
{
	int			pieces_count;
	t_solution	*solution;
	int			min_board_size;

	solution = malloc(sizeof(*solution));
	pieces_count = count_pieces(tetri_first);
	min_board_size = sqrt_up(pieces_count * 4);
	solution->solution = strnewarray(min_board_size, min_board_size);
	return (solution);
}

int			count_pieces(t_etris *tetri_first)
{
	int pieces_count;
	t_etris	*tetrimino;

	pieces_count = 0;
	tetrimino = tetri_first;
	while (tetrimino)
	{
		pieces_count++;
		tetrimino = tetrimino->next;
	}
	return (pieces_count);
}

int			find_solution(t_solution *solution, t_etris *tetrimino)
{
	if (!tetrimino)
		return (TRUE);
	while (move_tetrimino(solution, tetrimino))
		if (is_place_tetrimino(solution, tetrimino))
			if (find_solution(tetrimino->next))
				return (TRUE);
	return (FALSE);
}

int			is_place_for_tetrimino(t_solution *solution, t_etris *tetrimino)
{
	if (is_there_overlap(solution, tetrimino))
	{
		return (FALSE);
	}
	else
	{
		place_tetrimino(solution, tetrimino);
		return (TRUE);
	}
}

int			is_there_overlap(t_solution *solution, t_etris *tetrimino)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (check_overlap(solution, tetrimino->y_offset + tetrimino->coordinates[i++], tetrimino->x_offset + tetrimino->coordinates[i++])
			return (TRUE);
	}
	return (FALSE);
}

int			check_overlap(t_solution *solution, int y, int x)
{
	if (solution[y][x] != '.')
		return (TRUE);
	else
		return (FALSE);
}


void		place_tetrimino(t_solution *solution, t_etris *tetrimino)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	while (i < 8)
	{
		y = tetrimino->y_offset + tetrimino->coordinates[i++];
		x = tetrimino->x_offset + tetrimino->coordinates[i++];
		solution->solution[y][x] = tetrimino->c;
	}
}
int			move_tetrimino(t_solution *solution, t_etris *tetrimino)
{
	int	max_width;
	int max_height;

	max_width = tetrimino->x_offset + tetrimino->width;
	max_height = tetrimino->y_offset + tetrimino->height;
	if (max_width == solution->height && max_height == solution->height)
		return (FALSE);
	else if (max_width < solution->height)
	{
		tetrimino->x_offset++;
		return (TRUE);
	}
	else
	{
		tetrimino->x_offset = 0;
		tetrimino->y_offset++;
		return (TRUE);
	}

	//increments tetrimino offsets to find a place for it.
	//On first call initialises offsets to 0
	//if there is a place where it doesn't go outside of borders returns true
	//if the board is too small for it, returns false
}

void		grow_solution(t_solution *solution)
{
	size_t	new_height;
	size_t	i;

	new_height = solution->height + 1;
	i = 0;
	ft_free_ptr_array(solution->solution, solution->height);
	solution->solution = malloc(sizeof(*(solution->solution)) * new_height);
	while (i < new_height)
	{
		solution->solution[i] = ft_strnew(new_height);
		ft_memset(solution->solution[i], '.', new_height);
		++i;
	}
	solution->height = new_height;
}
