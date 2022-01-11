/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:52:11 by pniva             #+#    #+#             */
/*   Updated: 2022/01/11 15:56:22 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	sqrt_up(unsigned int num)
{
	unsigned int	i;

	i = 2;
	while (i * i < num)
		++i;
	return (i);
}

void	convert(t_etris *tetrimino)
{
	int	row;
	int	col;
	int	i;

	ft_bzero(tetrimino->coordinates, 8);
	row = 0;
	i = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tetrimino->yx[row][col] == '#')
			{
				tetrimino->coordinates[i++] = row;
				tetrimino->coordinates[i++] = col;
			}
			col++;
		}
		row++;
	}
}

void	find_size(t_etris *tetrimino)
{
	int	i;

	tetrimino->height = tetrimino->coordinates[0];
	tetrimino->width = tetrimino->coordinates[1];
	i = 2;
	while (i < 8)
	{
		if (tetrimino->coordinates[i] > tetrimino->height)
			tetrimino->height = tetrimino->coordinates[i];
		if (tetrimino->coordinates[i + 1] > tetrimino->width)
			tetrimino->width = tetrimino->coordinates[i + 1];
		i = i + 2;
	}
}

char	**strnewarray(int pointers, int chars)
{
	char	**array;
	int		i;

	i = 0;
	array = malloc(sizeof(*array) * pointers);
	while (i < pointers)
	{
		array[i] = ft_strnew(chars);
		++i;
	}
	return (array);
}
