# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grebrune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 11:02:44 by grebrune          #+#    #+#              #
#    Updated: 2023/10/01 21:23:37 by grebrune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
FLAGS = -Wall -Wextra -Werror -I lib_ft.h

NAME = rush-02

SRC = ft_create_megastr.c ft_split_num.c ft_strlen.c ft_strstr.c main.c check_input.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

.c.o:
	cc ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJ}
	cc ${FLAGS} ${OBJ} -o ${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re:  fclean all
