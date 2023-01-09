# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 13:59:11 by fvon-nag          #+#    #+#              #
#    Updated: 2023/01/09 17:13:49 by fvon-nag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libftprintf.a

SOURCES := libftprintf.c


OBJECTS = $(SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

$(NAME) : ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

all: ${NAME}

clean :
	rm -f $(OBJECTS) $(BOBJECTS)
fclean : clean
	rm -f $(NAME)
re : fclean all
