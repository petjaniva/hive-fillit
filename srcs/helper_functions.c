/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:52:11 by pniva             #+#    #+#             */
/*   Updated: 2022/01/14 10:35:03 by pniva            ###   ########.fr       */
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

void	save_yx_coordinates(t_etris *mino)
{
	int	row;
	int	col;
	int	i;

	ft_bzero(mino->coordinates, 8 * sizeof(int));
	row = 0;
	i = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (mino->yx[row][col] == '#')
			{
				mino->coordinates[i++] = row;
				mino->coordinates[i++] = col;
			}
			col++;
		}
		row++;
	}
}

void	find_size(t_etris *mino)
{
	int	i;

	mino->height = mino->coordinates[0];
	mino->width = mino->coordinates[1];
	i = 2;
	while (i < 8)
	{
		if (mino->coordinates[i] > mino->height)
			mino->height = mino->coordinates[i];
		if (mino->coordinates[i + 1] > mino->width)
			mino->width = mino->coordinates[i + 1];
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
