# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 14:58:09 by jmafueni          #+#    #+#              #
#    Updated: 2024/09/30 19:06:26 by jmafueni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBC =		ft_printf.c ft_putchar.c ft_puthex.c ft_puthex2.c \
	ft_putnbr.c ft_putptr.c ft_putstr.c ft_putunsigned.c ft_intlen.c

SRC = ${LIBC}

OBJS = ${SRC:.c=.o}

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar -rsc ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean:		clean;
	rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re
