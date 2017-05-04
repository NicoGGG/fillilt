# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/04 12:33:13 by nguelfi           #+#    #+#              #
#    Updated: 2017/05/04 14:04:59 by nguelfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB_DIR = ./lib
SRC_DIR = ./src
INCLUDE = ./include
OBJ_DIR = ./obj

SRC = ft_make_list.c ft_check_file.c main.c
BIN = ${SRC:%.c=%.o}
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CFLAGS = -Wall -Werror -Wextra --std=c99
OFLAGS = -pipe -flto
CFLAGS += $(OFLAGS)

LIBFT = $(LIB_DIR)/libft.a

all:
	mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	gcc $(CFLAGS) -I $(LIB_DIR) -I $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	gcc $(OFLAGS) $(OBJ) -L $(LIB_DIR) -l ft -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
