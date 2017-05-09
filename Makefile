# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/04 12:33:13 by nguelfi           #+#    #+#              #
#    Updated: 2017/05/04 16:35:27 by nguelfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB_DIR = ./lib
SRC_DIR = ./src
INCLUDE = ./include
OBJ_DIR = ./obj

SRC = input_checker.c ft_solver.c field_maker.c main.c 
BIN = ${SRC:%.c=%.o}
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CFLAGS = -Wall -Werror -Wextra

LIBFT = $(LIB_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) -I $(LIB_DIR) -I $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -L $(LIB_DIR) -l ft -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
