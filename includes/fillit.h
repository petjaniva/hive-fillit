/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:29:43 by pniva             #+#    #+#             */
/*   Updated: 2022/01/05 12:42:45 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct s_tetris
{
	char			c;
	char			yx[4][4];
	struct s_tetris	*next;
}				t_etris;

typedef struct s_olution
{
	size_t			height;
	char			**solution;
}				t_solution;

# define I		(int[8]) {0,0, 0,1, 0,2, 0,3}
# define I90	(int[8]) {0,0, 1,0, 2,0, 3,0}
# define O		(int[8]) {0,0, 1,0, 0,1, 1,1}
# define L		(int[8]) {0,0, 0,1, 0,2, 1,2}
# define L90	(int[8]) {0,0, 0,1, 1,0, 2,0}
# define L180	(int[8]) {0,0, 1,0, 1,1, 1,2}
# define L270	(int[8]) {0,1, 1,1, 2,0, 2,1}
# define J		(int[8]) {0,2, 1,0, 1,1, 1,2}
# define J90	(int[8]) {0,0, 0,1, 1,1, 2,1}
# define J180	(int[8]) {0,0, 0,1, 0,2, 1,0}
# define J270	(int[8]) {0,0, 1,0, 2,0, 2,1}
# define T		(int[8]) {0,0, 1,0, 2,0, 1,1}
# define T90	(int[8]) {0,1, 1,0, 1,1, 1,2}
# define T180	(int[8]) {0,1, 1,0, 1,1, 2,1}
# define T270	(int[8]) {0,0, 0,1, 0,2, 1,1}
# define Z		(int[8]) {0,0, 1,0, 1,1, 2,1}
# define Z90	(int[8]) {0,1, 0,2, 1,0, 1,1}
# define S		(int[8]) {0,1, 1,0, 1,1, 2,0}
# define S90	(int[8]) {0,0, 0,1, 1,1, 1,2}

#endif
