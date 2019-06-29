# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 01:51:05 by vinograd          #+#    #+#              #
#    Updated: 2019/06/28 20:48:14 by Nik              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS=*.c

OBJECTS=src/*.o

INCLUDES=./

all: $(NAME)

$(NAME):
	@make -C libft/ re
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	ar -rc $(NAME) $(OBJECTS) libft/*.o
	ranlib $(NAME)

clean:
	@make -C libft/ clean
	/bin/rm -f $(OBJECTS)

fclean: clean
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all