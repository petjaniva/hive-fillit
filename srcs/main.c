/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:25:16 by pniva             #+#    #+#             */
/*   Updated: 2022/01/11 10:19:49 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	print_tetriminos(t_etris *tetri_first)
{
	t_etris *tetrimino;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tetrimino = tetri_first;
	while (tetrimino)
	{
		ft_putchar(tetrimino->c);
		ft_putchar('\n');
		align(tetrimino->yx);
		while (j < 4)
		{
			while (i < 4)
			{
				ft_putchar(tetrimino->yx[j][i]);
				++i;
			}
			ft_putchar('\n');
			i = 0;
			++j;
		}
		j = 0;
		ft_putchar('\n');
		for(int i = 0; i < 8; i++)
		{
			ft_putnbr(tetrimino->coordinates[i]);
			ft_putchar(',');
		}
		ft_putchar('\n');
		tetrimino = tetrimino->next;
	}
	ft_putchar('\n');
}

void	print_solution(t_solution *solution)
{
	int	i;

	i = 0;
	while (i < solution->height)
	{
		ft_putendl(solution->solution[i]);
		++i;
	}
}

int	main(int argc, char *argv[])
{
	t_etris		*tetri_first;
	t_solution	*solution;
	
	if (argc != 2)
	{
		ft_putstr("Please give filename");
	}
	tetri_first = read_tetriminos(argv[1]);
	print_tetriminos(tetri_first);
	if (!validate_tetriminos(tetri_first))
	{
			ft_putstr("error");
			//ft_putendl("???");
			return (0);
	}
	//ft_putendl("???");
	solution = solve(tetri_first);
	if (!solution)
	{
		ft_putstr("error");
		return (0);
	}
	print_solution(solution);
	//free_memory(tetri_first, solution);*/
	
	return (0);
}
