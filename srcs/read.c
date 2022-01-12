/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:54:14 by pniva             #+#    #+#             */
/*   Updated: 2022/01/12 14:57:27 by bkandemi         ###   ########.fr       */
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
	{
		ft_putendl("unable to read file");
		return (NULL);
	}
	if (read_mino(fd, &tetri_first) == TRUE)
		return (tetri_first);
	return (NULL);
}


//TODO Too long, split or change?


/*
** Reads the next line from the file. If line exists and if strlen is = 0, checks if next line
** is line of a valid mino. If strlen of line was != 0, checks if that line
** is of a valid mino.
*/
// TODO error check for no new line between minos
/*int	there_is_next_mino(int fd, char **line)
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
}*/

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

/*t_etris	*get_next_mino(int fd, char **line)
{
	t_etris	*mino;
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
	mino = create_mino(yx);
	return (mino);
}*/

//TODO: rename align and convert?
t_etris	*create_mino(char yx[4][4])
{
	t_etris	*mino;

	mino = malloc(sizeof(*mino));
	if (!mino)
		return (NULL);
	ft_memcpy(mino->yx, yx, sizeof(int) * 16);
	align(mino->yx);
	convert(mino);
	mino->x_offset = 0;
	mino->y_offset = 0;
	mino->is_first_try = TRUE;
	find_size(mino);
	mino->next = NULL;
	return (mino);
}

int	read_mino(int fd, t_etris **head) 
{
	char *line;
	char	yx[4][4];
	int	i;
	int mino_in_list;

	i = 1;
	while (ft_get_next_line(fd, &line) > 0)
	{
		if (i % 5 == 0) //
		{
			if (ft_strlen(line) != 0)
				return (FALSE);
			add_mino_to_list(head, create_mino(yx));
			mino_in_list = TRUE;
			
		}
		else
		{
			if (check_line(line) == FALSE)
				return (FALSE);
			ft_strcpy(yx[i % 5 - 1], line);
			mino_in_list = FALSE;
		}
		i++;
	}
	if (i % 5 != 0)
		return (FALSE);
	if (mino_in_list == FALSE){
		add_mino_to_list(head, create_mino(yx));
	}
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

