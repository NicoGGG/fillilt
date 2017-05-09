# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/04 12:33:13 by nguelfi           #+#    #+#              #
#    Updated: 2017/05/09 16:24:08 by nguelfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB_DIR = ./libft
SRC_DIR = .
INC_DIR = .
OBJ_DIR = .

INC = fillit.h libft.h
INCLUDE = $(addprefix $(INC_DIR)/,$(INC)
SRC = input_checker.c ft_solver.c field_maker.c main.c 
BIN = ${SRC:%.c=%.o}
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CFLAGS = -Wall -Werror -Wextra

LIBFT = $(LIB_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	gcc $(CFLAGS) -I $(LIB_DIR) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(LIBFT) $(OBJ)
	gcc $(CFLAGS) $(OBJ) -L $(LIB_DIR) -l ft -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
