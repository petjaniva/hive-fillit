/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:54:14 by pniva             #+#    #+#             */
/*   Updated: 2022/01/14 10:05:08 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_etris	*from_file_to_list(char *filename)
{
	int		fd;
	t_etris	*tetri_first;


	tetri_first = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (read_mino(fd, &tetri_first) == FALSE)
		return (NULL);
	return (tetri_first);
}

int	read_mino(int fd, t_etris **head)
{
	char	*line;
	char	yx[4][4];
	int		i;

	i = 1;
	while (ft_get_next_line(fd, &line) > 0)
	{
		if (i % 5 == 0)
		{
			if (ft_strlen(line) != 0)
				return (FALSE);
			add_mino_to_list(head, create_mino(yx));
		}
		else
		{
			if (check_line(line) == FALSE)
				return (FALSE);
			ft_strcpy(yx[i % 5 - 1], line);
		}
		i++;
		ft_strdel(&line);
	}
	if (i % 5 != 0 || i > 5 * 26)
		return (FALSE);
	add_mino_to_list(head, create_mino(yx));
	return (TRUE);
}

void	add_mino_to_list(t_etris **head, t_etris *new)
{
	t_etris	*tmp;

	if (*head == NULL)
	{
		*head = new;
		(*head)->c = 'A';
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->c = tmp->c + 1;
	}
}

t_etris	*create_mino(char yx[4][4])
{
	t_etris	*mino;

	mino = malloc(sizeof(*mino));
	if (!mino)
		return (NULL);
	ft_memcpy(mino->yx, yx, sizeof(int) * 16);
	align_mino_topleft(mino->yx);
	save_yx_coordinates(mino);
	mino->x_offset = 0;
	mino->y_offset = 0;
	mino->is_first_try = TRUE;
	find_size(mino);
	mino->next = NULL;
	return (mino);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) != 4)
		return (FALSE);
	while (i < 4)
	{
		if (line[i] != '#' && line[i] != '.')
			return (FALSE);
		++i;
	}
	return (TRUE);
}
