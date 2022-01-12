/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:49:00 by bkandemi          #+#    #+#             */
/*   Updated: 2022/01/12 11:05:12 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	is_first_row_empty(char mino[4][4])
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (mino[0][col] == '#')
			return (FALSE);
		col++;
	}
	return (TRUE);
}

int	is_first_col_empty(char mino[4][4])
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (mino[row][0] == '#')
			return (FALSE);
		row++;
	}
	return (TRUE);
}

void	shift_cols(char mino[4][4])
{
	int	col;
	int	row;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 3)
		{
			mino[row][col] = mino[row][col + 1];
			col++;
		}
		mino[row][3] = '.';
		row++;
	}
}

void	shift_rows(char mino[4][4])
{
	int	col;
	int	row;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 3)
		{
			mino[row][col] = mino[row + 1][col];
			row++;
		}
		mino[3][col] = '.';
		col++;
	}
}

void	align(char mino[4][4])
{
	while (is_first_col_empty(mino) == TRUE)
		shift_cols(mino);
	while (is_first_row_empty(mino) == TRUE)
		shift_rows(mino);
}
