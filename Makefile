# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 01:51:05 by vinograd          #+#    #+#              #
#    Updated: 2019/06/30 01:19:44 by vinograd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS=src/*.c

OBJECTS=*.o

INCLUDES=src/

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