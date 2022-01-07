/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:56:46 by pniva             #+#    #+#             */
/*   Updated: 2022/01/07 09:17:56 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	validate_tetriminos(t_etris *tetri_first)
{
	t_etris	*tetrimino;

	tetrimino = tetri_first;
	while (tetrimino)
	{
		convert(tetrimino->yx, tetrimino->coordinates);
		if (!check_shape(tetrimino->coordinates))
			return (FALSE);
		tetrimino = tetrimino->next;
	}
	return (TRUE);
}

int	check_shape(int coordinates[8])
{
	int	i;

	i = 0;
	while (i < 19)
	{
		if (!ft_memcmp(coordinates, TETRIMINOS[i], 8))
			return (TRUE);
		++i;
	}
	return (FALSE);
}
