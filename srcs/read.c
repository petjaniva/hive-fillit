/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:54:14 by pniva             #+#    #+#             */
/*   Updated: 2022/01/06 14:04:14 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		check_line(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) != 4)
		return (FALSE);
	while (line[i])
	{
		if (line[i] != '#' && line[i] != '.')
			return (FALSE);
		++i;
	}
	return (TRUE);
}

/*
** Reads the next line from the file. If line exists and if strlen is = 0, checks if next line
** is line of a valid tetrimino. If strlen of line was != 0, checks if that line
** is of a valid tetrimino.
*/

int		there_is_next_tetrimino(int fd, char **line)
{
	if (ft_get_next_line(fd, line))
	{
		if (ft_strlen(*line) == 0)
		{
			if (ft_get_next_line(fd, line))
				if (check_line(*line))
					return (TRUE);
		}
		else if (check_line(*line))
			return (TRUE);
	}
		return (FALSE);
}

t_etris	*get_next_tetrimino(int fd, char **line)
{
	t_etris	*tetrimino;
	char	yx[4][4];
	int		i;

	i = 0;
	while (i <4)
	{
		ft_strcpy(yx[i], *line);
		if(!ft_get_next_line(fd, line) && i != 3)
			return (NULL);
		++i;
	}
	tetrimino = malloc(sizeof(t_etris));
	ft_memcpy(tetrimino->yx, yx, sizeof(yx));
	return (tetrimino);
}


t_etris	*from_file_to_list(int fd)
{
	char	*line;
	t_etris	*tetri_first;
	t_etris	*tetri_old;
	t_etris	*tetri_new;

	tetri_first = NULL;
	while (there_is_next_tetrimino(fd, &line))
	{
		tetri_new = get_next_tetrimino(fd, &line);
		if (!tetri_new)
		{
			//free_list(tetri_first); //not implemented yet
			return (NULL);
		}
		if (!tetri_first)
		{
			tetri_first = tetri_new;
			tetri_first->c = 'a';
		}
		else
		{
			tetri_new->c =tetri_old->c + 1;
			tetri_old->next = tetri_new;
		}
			
		tetri_old = tetri_new;
	}
	return (tetri_first);
}

t_etris	*read_tetriminos(char *filename)
{
	int	fd;	
	t_etris *tetri_first;

	fd = open(filename, O_RDONLY);
	tetri_first = from_file_to_list(fd);
	return (tetri_first);
}
