/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:29:43 by pniva             #+#    #+#             */
/*   Updated: 2022/01/05 07:27:44 by pniva            ###   ########.fr       */
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
}

#endif
