# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/04 12:33:13 by nguelfi           #+#    #+#              #
#    Updated: 2017/05/05 14:39:45 by nguelfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB_DIR = ./lib
SRC_DIR = ./src
INCLUDE = ./include
OBJ_DIR = ./obj

SRC = input_checker.c ft_solver.c field_maker.c main.c 
BIN = ${SRC:%.c=%.o}
OBJ = $(addprefix $(SRC_DIR)/,$(SRC))

CFLAGS = -Wall -Werror -Wextra

LIBFT = $(LIB_DIR)/libft.a

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIB_DIR) --no-print-directory
	gcc $(CFLAGS) $(OBJ) -I $(LIB_DIR) -I $(INCLUDE) -c
	gcc $(CFLAGS) $(BIN) -L $(LIB_DIR) -l ft -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	/bin/rm -rf $(BIN)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
