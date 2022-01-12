/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:54:14 by pniva             #+#    #+#             */
/*   Updated: 2022/01/12 09:25:47 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_etris	*read_tetriminos(char *filename)
{
	int		fd;	
	t_etris	*tetri_first;

	fd = open(filename, O_RDONLY);
	tetri_first = from_file_to_list(fd);
	return (tetri_first);
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
			return (NULL);
		if (!tetri_first)
		{
			tetri_first = tetri_new;
			tetri_first->c = 'A';
		}
		else
		{
			if (tetri_old->c == 'Z')
				return (NULL);
			tetri_new->c = tetri_old->c + 1;
			tetri_old->next = tetri_new;
		}	
		tetri_old = tetri_new;
	}
	return (tetri_first);
}

/*
** Reads the next line from the file. If line exists and if strlen is = 0, checks if next line
** is line of a valid tetrimino. If strlen of line was != 0, checks if that line
** is of a valid tetrimino.
*/

int	there_is_next_tetrimino(int fd, char **line)
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

int	check_line(char *line)
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

t_etris	*get_next_tetrimino(int fd, char **line)
{
	t_etris	*tetrimino;
	char	yx[4][4];
	int		i;

	i = 0;
	while (i < 4)
	{
		ft_strcpy(yx[i], *line);
		if (!ft_get_next_line(fd, line) && i != 3)
			return (NULL);
		++i;
	}
	tetrimino = create_tetrimino(yx);
	return (tetrimino);
}

t_etris	*create_tetrimino(char yx[4][4])
{
	t_etris	*tetrimino;

	tetrimino = malloc(sizeof(*tetrimino));
	if (!tetrimino)
		return (NULL);
	ft_memcpy(tetrimino->yx, yx, sizeof(int) * 16);
	align(tetrimino->yx);
	convert(tetrimino);
	tetrimino->x_offset = 0;
	tetrimino->y_offset = 0;
	tetrimino->is_first_try = TRUE;
	find_size(tetrimino);
	tetrimino->next = NULL;
	return (tetrimino);
}
