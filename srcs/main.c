/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:25:16 by pniva             #+#    #+#             */
/*   Updated: 2022/01/14 14:54:10 by pniva            ###   ########.fr       */
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
	ft_putendl("printminos");
	while (mino)
	{
		ft_putchar(mino->c);
		ft_putchar('\n');
		align_mino_topleft(mino->yx);
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
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < map->height)
	{
		ft_putendl(map->board[i]);
		++i;
	}
}

void	free_memory(t_etris *mino, t_solution *map)
{
	t_etris	*tmp;

	while (mino)
	{
		tmp = mino->next;
		free(mino);
		mino = tmp;
	}
	if (map)
	{
		ft_free_ptr_array((void **)map->board, map->height);
		free(map);
	}
}

void	handle_errors(int error_code, t_etris *tetri, t_solution *map)
{
	free_memory(tetri, map);
	ft_putendl("error");
	exit(error_code);
}

int	main(int argc, char *argv[])
{
	t_etris		*tetri_first;
	t_solution	*map;

	map = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit file_name");
		exit(1);
	}
	tetri_first = from_file_to_list(argv[1]);
	if (!tetri_first)
		handle_errors(2, tetri_first, map);
	if (!validate_minos(tetri_first))
		handle_errors(3, tetri_first, map);
	map = solve(tetri_first);
	if (!map)
		handle_errors(4, tetri_first, map);
	print_solution(map);
	free_memory(tetri_first, map);
	return (0);
}
