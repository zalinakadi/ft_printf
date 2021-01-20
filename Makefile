# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eproveme <eproveme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 13:43:31 by eproveme          #+#    #+#              #
#    Updated: 2021/01/20 20:48:21 by eproveme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = libftprintf.a

HEADER = ft_printf.h

SRCS = ft_printf.c ft_flag.c ft_add.c ft_puts.c ft_specs.c ft_parser.c \
		ft_putadd.c ft_str.c ft_di.c ft_u.c ft_x.c ft_hex.c ft_p.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER) $(L_HEADER)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
