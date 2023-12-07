/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:13:34 by faboussa          #+#    #+#             */
/*   Updated: 2023/10/01 19:47:44 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_ft.h"

void	ft_print_to_find(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ')
		i++;
	while (str[i] == ' ' || str[i] == ':')
		i++;
	while (str[i] != '\n')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_strstr(char *to_find, char *str)
{
	int	i;
	int	x;
	int	len;
	int	size;

	i = 0;
	len = ft_strlen(to_find);
	size = ft_strlen(str);
	while (str[i])
	{
		x = 0;
		while (to_find[x] == str[i])
		{
			x++;
			i++;
		}
		if (len == x)
		{
			ft_print_to_find(&str[i - x]);
			i = size;
		}
		i++;
	}
}
