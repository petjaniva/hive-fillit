/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:25:16 by pniva             #+#    #+#             */
/*   Updated: 2022/01/06 07:53:58 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char *argv[])
{
	t_etris	*tetri_first;
	char	**solution;
	
	if (!argc == 2)
	{
		ft_putstr_fd("Please give filename", 1);
	}
	tetri_first = read_tetriminos(argv[1]);
	if (!validate_tetriminos(tetri_first))
	{
			ft_putstr_fd("error", 1);
			return (0);
	}
	solution = solve(tetri_first);
	if (!solution)
	{
		ft_putstr_fd("error", 1);
		return (0);
	}
	print(solution);
	free_memory(tetri_first, solution);
	return (0);
}
