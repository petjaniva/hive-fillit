/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:25:16 by pniva             #+#    #+#             */
/*   Updated: 2022/01/05 10:33:52 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char *argv[])
{
	char	**tetriminos;
	char	**solution;
	
	if (!argc == 2)
	{
		ft_putstr_fd("Please give filename", 1);
	}
	tetriminos = read_tetriminos(argv[1]);
	if (!validate_tetriminos(tetriminos))
	{
			ft_putstr_fd("error", 1);
			return (0);
	}
	solution = solve(tetriminos);
	if (!solution)
	{
		ft_putstr_fd("error", 1);
		return (0);
	}
	print(solution);
	free_memory(tetriminos, solution);
	return (0);
}
