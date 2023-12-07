/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:01:21 by grebrune          #+#    #+#             */
/*   Updated: 2023/10/01 21:45:28 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FT_H
# define LIB_FT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_split_num(char *str, char *mega_str);
int		ft_strlen(char *str);
char	*ft_create_megastr(int count, char *name_dict);
int		ft_open_read(char *name_dict);
void	ft_strstr(char *str, char *to_find);
int		check_errors(int ac, char **av);
void	ft_aff_nbr(int nbr);

#endif
