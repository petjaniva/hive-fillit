/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:56:46 by pniva             #+#    #+#             */
/*   Updated: 2022/01/15 10:58:41 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	validate_minos(t_etris *tetri_first)
{
	t_etris	*mino;
	int		connections;

	mino = tetri_first;
	while (mino)
	{
		if (count_hashtag(mino->yx) != 4)
			return (FALSE);
		connections = count_connections(mino->yx);
		if (connections != 6 && connections != 8)
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

int	count_connections(char yx[4][4])
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (i++ < 3)
	{
		j = -1;
		while (j++ < 3)
		{
			if (yx[i][j] == '#')
			{
				if (i - 1 >= 0 && yx[i - 1][j] == '#')
					count++;
				if (i + 1 < 4 && yx[i + 1][j] == '#')
					count++;
				if (j - 1 >= 0 && yx[i][j - 1] == '#')
					count++;
				if (j + 1 < 4 && yx[i][j + 1] == '#')
					count++;
			}
		}
	}
	return (count);
}
