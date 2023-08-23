# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acuva-nu <acuva-nu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 10:45:20 by acuva-nu          #+#    #+#              #
#    Updated: 2022/12/01 17:30:06 by acuva-nu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c ft_csdiu.c ft_hex.c


OBJS		= $(SRCS:.c=.o)


CC		= gcc

CFLAGS 		= -Wall -Wextra -Werror

NAME		= libftprintf.a

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm -f $(OBJS) $(OBJSB)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
