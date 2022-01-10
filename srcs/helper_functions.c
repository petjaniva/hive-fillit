/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:52:11 by pniva             #+#    #+#             */
/*   Updated: 2022/01/10 14:07:29 by bkandemi         ###   ########.fr       */
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

int	is_first_row_empty(char tetrimino[4][4])
{
	int	col;

	col = 0;	
	while (col < 4)
	{
		if (tetrimino[0][col] == '#')
			return (FALSE);
		col++;
	}
	return (TRUE);
}

int	is_first_col_empty(char tetrimino[4][4])
{
	int	row;

	row = 0;	
	while (row < 4)
	{
		if (tetrimino[row][0] == '#')
			return (FALSE);
		row++;
	}
	return (TRUE);
}

void	shift_cols(char tetrimino[4][4])
{
	int	col;
	int	row;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 3)
		{
			tetrimino[row][col] = tetrimino[row][col + 1];
			col++;
		}
		tetrimino[row][3] = '.';
		row++;
	}
}

void	shift_rows(char tetrimino[4][4])
{
	int	col;
	int	row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 3)
		{
			tetrimino[row][col] = tetrimino[row + 1][col];
			row++;
		}
		tetrimino[3][col] = '.';
		col++;
	}
}

void	align(char tetrimino[4][4])
{
	while (is_first_col_empty(tetrimino) == TRUE)
		shift_cols(tetrimino);
	while (is_first_row_empty(tetrimino) == TRUE)
		shift_rows(tetrimino);
}

void	convert(char tetrimino[4][4], int coordinates[8])
{
	int	row;
	int	col;
	int	i;
	
	i = 0;
	while (i < 8)
	{
		coordinates[i] = 0;
		i++;
	}  // we can use ft_bzero here ??
	row = 0;
	i = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tetrimino[row][col] == '#')
			{
				coordinates[i++] = row;
				coordinates[i++] = col;	
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
