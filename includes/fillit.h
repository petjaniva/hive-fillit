/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:29:43 by pniva             #+#    #+#             */
/*   Updated: 2022/01/08 09:02:36 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <fcntl.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct s_tetris
{
	char			c;
	char			yx[4][4];
	int				coordinates[8];
	int				x_offset;
	int				y_offset;
	struct s_tetris	*next;
}				t_etris;

typedef struct s_olution
{
	size_t			height;
	char			**solution;
}				t_solution;

# define I		(int[8]) {0,0, 1,0, 2,0, 3,0}
# define I90	(int[8]) {0,0, 0,1, 0,2, 0,3}
# define J		(int[8]) {0,1, 1,1, 2,0, 2,1}
# define J90	(int[8]) {0,0, 0,1, 1,1, 1,2}
# define J180	(int[8]) {0,0, 0,1, 1,0, 2,0}
# define J270	(int[8]) {0,0, 0,1, 0,2, 1,2}
# define L		(int[8]) {0,0, 1,0, 2,0, 2,1}
# define L90	(int[8]) {0,0, 0,1, 0,2, 1,0}
# define L180	(int[8]) {0,0, 0,1, 1,1, 2,1}
# define L270	(int[8]) {0,2, 1,0, 1,1, 1,2}
# define O		(int[8]) {0,0, 0,1, 1,0, 1,1}
# define S		(int[8]) {0,1, 0,2, 1,0, 1,1}
# define S90	(int[8]) {0,0, 1,0, 1,1, 2,1}
# define T		(int[8]) {0,0, 0,1, 0,2, 1,1}
# define T90	(int[8]) {0,1, 1,0, 1,1, 2,1}
# define T180	(int[8]) {0,1, 1,0, 1,1, 1,2}
# define T270	(int[8]) {0,0, 0,1, 1,1, 2,0}
# define Z		(int[8]) {0,0, 0,1, 1,1, 1,2}
# define Z90	(int[8]) {0,1, 1,0, 1,1, 2,0}

# define TETRIMINOS		(int[19][8]) {{0,0, 1,0, 2,0, 3,0},\
						{0,0, 0,1, 0,2, 0,3},\
						{0,1, 1,1, 2,0, 2,1},\
						{0,0, 0,1, 1,1, 1,2},\
						{0,0, 0,1, 1,0, 2,0},\
						{0,0, 0,1, 0,2, 1,2},\
						{0,0, 1,0, 2,0, 2,1},\
						{0,0, 0,1, 0,2, 1,0},\
						{0,0, 0,1, 1,1, 2,1},\
						{0,2, 1,0, 1,1, 1,2},\
						{0,0, 0,1, 1,0, 1,1},\
						{0,1, 0,2, 1,0, 1,1},\
						{0,0, 1,0, 1,1, 2,1},\
						{0,0, 0,1, 0,2, 1,1},\
						{0,1, 1,0, 1,1, 2,1},\
						{0,1, 1,0, 1,1, 1,2},\
						{0,0, 0,1, 1,1, 2,0},\
						{0,0, 0,1, 1,1, 1,2},\
						{0,1, 1,0, 1,1, 2,0}}

int		check_line(char *line);
int		there_is_next_tetrimino(int fd, char **line);
t_etris	*get_next_tetrimino(int fd, char **line);
t_etris	*from_file_to_list(int fd);
t_etris	*read_tetriminos(char *filename);
int	sqrt_up(unsigned int num);
int	is_first_row_empty(char tetrimino[4][4]);
int	is_first_col_empty(char tetrimino[4][4]);
void	shift_cols(char tetrimino[4][4]);
void	shift_rows(char tetrimino[4][4]);
void	align(char tetrimino[4][4]);
void	convert(char tetrimino[4][4], int coordinates[8]);
int	check_shape(int coordinates[8]);
int	validate_tetriminos(t_etris *tetri_first);

#endif
