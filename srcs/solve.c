/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 09:41:38 by pniva             #+#    #+#             */
/*   Updated: 2022/01/07 14:30:16 by pniva            ###   ########.fr       */
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

int			find_solution(t_solution *solution, t_etris *tetrimino)
{
	if (!tetrimino)
		return (TRUE);
	while (!place_tetrimino(solution, tetrimino))
		if (!move_tetrimino(tetrimino))
			return (FALSE);
	if (find_solution(solution, tetrimino->next))
		return (TRUE);
	return (FALSE);
	
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
