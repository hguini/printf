# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguini <hguini@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 15:50:14 by hguini            #+#    #+#              #
#    Updated: 2021/01/20 19:38:48 by hguini           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ft_printf.c ft_parse.c ft_print_width.c ft_tools.c ft_if_c.c ft_if_di.c ft_if_p.c ft_if_percent.c ft_if_s.c ft_if_u.c ft_if_x.c

FTOBJ	= ./libft/*.o

HEADER	= libprintf.h

INCLUDES	= .

OBJ		= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror

all: make _libft $(NAME)

%.o: %.c	$(HEADER)
	gcc -c $(CFLAG) -I$(INCLUDES) $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $(FTOBJ)
	ranlib $(NAME)

make _libft:
	$(MAKE) -C ./libft/

clean:
	$(MAKE) -C ./libft/ fclean
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean re all clean
