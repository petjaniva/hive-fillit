/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:56:46 by pniva             #+#    #+#             */
/*   Updated: 2022/01/13 13:26:28 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	validate_minos(t_etris *tetri_first)
{
	t_etris	*mino;

	mino = tetri_first;
	while (mino)
	{
		if (!check_shape(mino->coordinates))
			return (FALSE);
		mino = mino->next;
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
