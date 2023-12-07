/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:31:18 by faboussa          #+#    #+#             */
/*   Updated: 2023/10/01 21:18:00 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

int	check_sign(int ac, char **av, int *pi)
{
	int	i;

	i = *pi;
	while (av[ac - 1][i] == '+' || av[ac - 1][i] == '-')
	{
		if (av[ac - 1][i] == '+' && av[ac - 1][i + 1] == '+')
			return (1);
		if (av[ac - 1][i] == '-')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	*pi = i;
	return (0);
}

int	check_errors(int ac, char **av)
{
	int	i;
	int	*pi;

	i = 0;
	pi = &i;
	if (ac > 3 || ac == 1)
		return (1);
	else
	{
		while (av[ac - 1][i] == ' '
			|| (av[ac - 1][i] >= 9 && av[ac - 1][i] <= 13))
			i++;
		check_sign(ac, av, pi);
		while (av[ac - 1][i] == '0')
			i++;
		while (av[ac - 1][i] >= '0' && av[ac - 1][i] <= '9')
			i++;
		if (av[ac - 1][i - 1] >= '0' && av[ac -1][i - 1] <= '9')
			return (0);
	}
	return (1);
}
