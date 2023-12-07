/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:13:12 by grebrune          #+#    #+#             */
/*   Updated: 2023/10/01 21:12:17 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_ft.h"

void	ft_num(char c, char *mega_str)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	ft_strstr(str, mega_str);
}

int	ft_cut(int len, char *mega_str)
{
	char	*cut;
	int		i;

	i = 0;
	cut = malloc(sizeof(char) * (len + 1));
	if (cut == NULL)
		return (-1);
	cut[i] = '1';
	while (++i < len)
		cut[i] = '0';
	cut[i] = '\0';
	ft_strstr(cut, mega_str);
	free (cut);
	return (0);
}

void	ft_tens(char *str, int n, char *mega_str)
{
	int		i;
	char	tens[3];

	i = 0;
	if (str[i + 1] == '0' || (str[i] == '1' && str[i + 1] != '0'))
	{
		while (i < n)
		{
			tens[i] = str[i];
			i++;
		}
		tens[i] = '\0';
		ft_strstr(tens, mega_str);
	}
	else
	{
		tens[i] = str[i];
		while (++i < n)
			tens[i] = '0';
		tens[i] = '\0';
		ft_strstr(tens, mega_str);
		write(1, "-", 1);
		ft_num(str[1], mega_str);
	}
}

int	ft_find_next(char *str, char *mega_str, int *i, int *len)
{
	if (*len % 3 == 0)
	{
		ft_num(str[*i], mega_str);
		write(1, " ", 1);
		if (-1 == ft_cut(*len, mega_str))
			return (-1);
		*i += 1;
	}
	else if (*len % 2 == 0)
	{
		ft_tens(&str[*i], 2, mega_str);
		*i += 2;
	}
	else if (*i == 0)
	{
		ft_num(str[*i], mega_str);
		*i += 1;
	}
	return (0);
}

int	ft_split_num(char *str, char *mega_str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (-1 == (ft_find_next(str, mega_str, &i, &len)))
			return (-1);
		if (str[i] != '\0')
			write(1, " ", 1);
		len -= i;
	}
	return (0);
}
