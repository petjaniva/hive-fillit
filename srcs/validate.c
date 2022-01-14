/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:56:46 by pniva             #+#    #+#             */
/*   Updated: 2022/01/14 10:06:11 by bkandemi         ###   ########.fr       */
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
		if (count_hashtag(mino->yx) != 4)
			return (FALSE);
		if (!check_shape(mino->coordinates))
			return (FALSE);
		mino = mino->next;
	}
	return (TRUE);
}

int	count_hashtag(char yx[4][4])
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (yx[i][j] == '#')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_shape(int coordinates[8])
{
	int	i;

	i = 0;
	while (i < 19)
	{
		if (!ft_memcmp(coordinates, TETRIMINOS[i], 8 * sizeof(int)))
			return (TRUE);
		++i;
	}
	return (FALSE);
}
