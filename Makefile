# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 10:36:04 by yribeiro          #+#    #+#              #
#    Updated: 2017/11/07 13:11:19 by yribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
CC = gcc
INCLUDES = includes
FLAGS = -Wall -Werror -Wextra
SRCS = filler.c reader.c
SRCSREP = srcs
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : $(SRCSREP)/%.c
	$(CC) $(FLAGS) -I$(INCLUDES) -Ilibft -c $?
$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(FLAG) -I$(INCLUDES) $^ -Llibft -lft -o $@
clean :
	make clean -C libft
	rm -f $(OBJS)
fclean : clean
	make fclean -C libft
	rm -f $(NAME)
re : fclean all
