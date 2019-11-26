# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 14:51:25 by lkarlon-          #+#    #+#              #
#    Updated: 2019/09/04 18:03:43 by lkarlon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	./resources/players/lkarlon.filler

FILES			=	./srcs/main.c \
					./srcs/make_warm.c \
					./srcs/support.c

LIB_FT			=	libft.a

LIB_DIR			=	./srcs/libft

WWW				=	-Wall -Werror -Wextra

FLAGS			=	$(WWW) $(LIB_DIR)/$(LIB_FT) 

HEADER			=	./includes/filler.h

CC				=	gcc

OBJ				= $(FILES:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
				$(MAKE) -C $(LIB_DIR) 
				$(CC) $(OBJ) -o $(NAME) $(FLAGS)

%.o: %.c $(HEADER)
				$(CC) -c $< -o $@

clean:
				@rm -f ./srcs/*.o
				@rm -f ./srcs/libft/*.o
				
fclean: clean
				@$(MAKE) -C $(LIB_DIR) fclean 
				@rm -f $(NAME)

re: fclean all