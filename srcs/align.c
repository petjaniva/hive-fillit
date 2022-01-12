/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:49:00 by bkandemi          #+#    #+#             */
/*   Updated: 2022/01/12 22:11:27 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

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

void	align_mino_topleft(char tetrimino[4][4])
{
	while (is_first_col_empty(tetrimino) == TRUE)
		shift_cols(tetrimino);
	while (is_first_row_empty(tetrimino) == TRUE)
		shift_rows(tetrimino);
}
