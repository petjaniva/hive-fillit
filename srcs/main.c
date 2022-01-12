/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:25:16 by pniva             #+#    #+#             */
/*   Updated: 2022/01/12 10:44:13 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	print_minos(t_etris *tetri_first)
{
	t_etris *mino;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mino = tetri_first;
	while (mino)
	{
		ft_putchar(mino->c);
		ft_putchar('\n');
		align(mino->yx);
		while (j < 4)
		{
			while (i < 4)
			{
				ft_putchar(mino->yx[j][i]);
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
			ft_putnbr(mino->coordinates[i]);
			ft_putchar(',');
		}
		ft_putchar('\n');
		mino = mino->next;
	}
	ft_putchar('\n');
}

void	print_solution(t_solution *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		ft_putendl(map->board[i]);
		++i;
	}
}

int	main(int argc, char *argv[])
{
	t_etris		*tetri_first;
	t_solution	*map;
	
	if (argc != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" file_name");
		return (1);
	}
	tetri_first = read_minos(argv[1]);
	if (!validate_minos(tetri_first))
	{
			ft_putendl("error");
			return (2);
	}
	map = solve(tetri_first);
	if (!map)
	{
		ft_putendl("error");
		return (3);
	}
	print_solution(map);
	//free_memory(tetri_first, map);*/
	
	return (0);
}
