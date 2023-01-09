# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 13:59:11 by fvon-nag          #+#    #+#              #
#    Updated: 2023/01/09 14:00:26 by fvon-nag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libftprintf.a

SOURCES :=


OBJECTS = $(SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

$(NAME) : ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

all: ${NAME} bonus

clean :
	rm -f $(OBJECTS) $(BOBJECTS)
fclean : clean
	rm -f $(NAME)
re : fclean all
