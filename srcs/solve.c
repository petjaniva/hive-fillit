/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:41:38 by pniva             #+#    #+#             */
/*   Updated: 2022/01/10 14:36:08 by bkandemi         ###   ########.fr       */
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

int			find_solution(t_solution *solution, t_etris *tetrimino)
{
	if (!tetrimino)
		return (TRUE);
	while (move_tetrimino(solution, tetrimino))
		if (place_tetrimino(solution, tetrimino))
			if (find_solution(tetrimino->next))
				return (TRUE);
	return (FALSE);
}

int			place_tetrimino(t_solution *solution, t_etris *tetrimino)
{
	//tries to place the tetrimino according to the stored offsets.
	//checks for overlaps with other pieces
	//return true is placing succeeds, false if not

}

int			move_tetrimino(t_solution *solution, t_etris *tetrimino)
{	
	int	max_width;
	int max_height;

	max_width = tetrimino->x_offset + tetrimino->width;
	max_height = tetrimino->y_offset + tetrimino->height;
	if (max_width == solution->height - 1 && max_height == solution->height - 1)
		return (FALSE);
	else if (max_width < solution->height - 1)
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
}
