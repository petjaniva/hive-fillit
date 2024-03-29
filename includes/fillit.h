/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:29:43 by pniva             #+#    #+#             */
/*   Updated: 2022/01/15 12:31:59 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <string.h>
# define TRUE 1
# define FALSE 0

typedef struct s_tetris
{
	char			letter;
	char			yx[4][4];
	int				coordinates[8];
	int				x_offset;
	int				y_offset;
	struct s_tetris	*next;
}				t_etris;

typedef struct s_olution
{
	int			height;
	char		**board;
}				t_solution;

int			check_line(char *line);
int			there_is_next_mino(int fd, char **line);
t_etris		*get_next_mino(int fd, char **line);
t_etris		*from_file_to_list(char *filename);
t_etris		*create_mino(char yx[4][4]);
int			sqrt_up(unsigned int num);
int			is_first_row_empty(char mino[4][4]);
int			is_first_col_empty(char mino[4][4]);
void		shift_cols(char mino[4][4]);
void		shift_rows(char mino[4][4]);
void		align_mino_topleft(char tetrimino[4][4]);
void		save_yx_coordinates(t_etris *mino);
int			check_shape(int coordinates[8]);
int			validate_minos(t_etris *tetri_first);
char		**strnewarray(int pointers, int chars);
void		find_size(t_etris *mino);
t_solution	*solve(t_etris *tetri_first);
t_solution	*initiate_map(t_etris *tetri_first);
int			count_minos(t_etris *tetri_first);
int			find_solution(t_solution *map, t_etris *mino);
int			is_place_for_mino(t_solution *map, t_etris *mino);
int			is_there_overlap(t_solution *map, t_etris *mino);
int			check_overlap(t_solution *map, int y, int x);
void		place_mino(t_solution *map, t_etris *mino);
int			move_mino(t_solution *map, t_etris *mino);
t_solution	*grow_board(t_solution *map);
void		print_solution(t_solution *map);
void		print_minos(t_etris *tetri_first);
int			check_if_mino_fit(int min_board_size, t_etris *tetri_first);
void		remove_placement(t_solution *map, t_etris *mino);
int			find_place_for_mino(t_solution *map, t_etris *mino);
int			try_placing_mino(t_solution *map, t_etris *mino);
int			mino_in_bounds(t_solution *map, t_etris *mino);
void		increment_offsets(t_solution *map, t_etris *mino);
void		move_to_origin(t_etris *mino);
int			read_mino(int fd, t_etris **head);
int			mino_to_list(t_etris **head, t_etris *new);
int			count_hashtag(char yx[4][4]);
int			count_connections(char yx[4][4]);
void		free_memory(t_etris *mino, t_solution *map);
int			free_line_return_false(char **line);

#endif
