/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:52:11 by pniva             #+#    #+#             */
/*   Updated: 2022/01/15 12:27:15 by pniva            ###   ########.fr       */
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
	move_to_origin(mino);
}

void	move_to_origin(t_etris *mino)
{
	int	num;
	int	i;
	int	y_or_x;

	i = 0;
	if (mino->coordinates[0] != 0)
		y_or_x = 0;
	else
		y_or_x = 1;
	num = mino->coordinates[y_or_x];
	while (i < 8)
	{
		if (i % 2 == y_or_x)
			mino->coordinates[i] = mino->coordinates[i] - num;
		else
			mino->coordinates[i] = mino->coordinates[i];
		++i;
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

int	free_line_return_false(char **line)
{
	ft_strdel(line);
	return (FALSE);
}
