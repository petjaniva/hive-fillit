/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:52:11 by pniva             #+#    #+#             */
/*   Updated: 2022/01/05 15:08:09 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	*convert(char tetrimino[4][4], int coordinates[8])
{
	//work in progress
}
