/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:41:38 by pniva             #+#    #+#             */
/*   Updated: 2022/01/08 14:07:13 by pniva            ###   ########.fr       */
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
	solution->solution = strnewarrarr(min_board_size, min_board_size);
	return (solution);
}

int			find_solution(t_solution *solution, t_etris *tetrimino)
{
	if (!tetrimino)
		return (TRUE);
	while (!place_tetrimino(solution, tetrimino))
		if (!move_tetrimino(solution, tetrimino))
			return (FALSE);
	if (find_solution(solution, tetrimino->next))
		return (TRUE);
	return (FALSE);
}

int			place_tetrimino(t_solution *solution, t_etris *tetrimino)
{
	//tries to place the tetrimino according to the stored offsets.
	//return true is placing succeeds, false if not
}

int			move_tetrimino(t_solution *solution, t_etris *tetrimino)
{
	//increments tetrimino offsets to find a place for it
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
}
