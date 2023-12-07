/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:37:47 by faboussa          #+#    #+#             */
/*   Updated: 2023/10/01 22:52:50 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_ft.h"

int	ft_make_mega(char *str, char *name_dict, char *mega_str)
{
	int	count;

	count = ft_open_read(name_dict);
	if (count == -1)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	mega_str = ft_create_megastr(count, name_dict);
	if (mega_str == NULL)
	{
		free (mega_str);
		write(1, "Dict Error\n", 11);
		return (1);
	}
	if (-1 == (ft_split_num(str, mega_str)))
	{
		free (mega_str);
		write(1, "Error Malloc\n", 13);
		return (1);
	}
	free (mega_str);
	return (0);
}

int	main(int ac, char **av)
{
	char	*mega_str;
	char	*name_dict;
	char	*value;

	mega_str = NULL;
	value = NULL;
	name_dict = NULL;
	if (check_errors(ac, av) == 0)
	{
		if (ac == 3)
		{
			name_dict = av[1];
			value = av[2];
		}
		else
		{
			name_dict = "numbers.dict";
			value = av[1];
		}
		if (ft_make_mega(value, name_dict, mega_str) == 1)
			return (1);
		return (0);
	}
}
