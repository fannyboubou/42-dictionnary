/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_megastr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:49:03 by grebrune          #+#    #+#             */
/*   Updated: 2023/10/01 22:44:10 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_ft.h"

char	*ft_create_megastr(int count, char *name_dict)
{
	int		fd;
	int		i;
	char	*mega_str;

	mega_str = malloc(sizeof(char) * (count + 1));
	if (mega_str == NULL)
		return (mega_str);
	fd = open(name_dict, O_RDONLY);
	if (fd == -1)
	{
		mega_str = NULL;
		return (mega_str);
	}
	i = 0;
	while (i < count)
	{
		i += read(fd, &mega_str[i], 200);
	}
	mega_str[i] = '\0';
	if ((close(fd)) == -1)
	{
		mega_str = NULL;
		return (mega_str);
	}
	return (mega_str);
}

int	ft_open_read(char *name_dict)
{
	int		fd;
	char	str[250];
	int		count;
	int		i;

	fd = open(name_dict, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 1;
	count = 0;
	while (i > 0)
	{
		i = read(fd, str, 200);
		count += i;
	}
	if ((close(fd)) == -1)
	{
		return (-1);
	}
	return (count);
}
