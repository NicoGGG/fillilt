# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguelfi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/04 12:33:13 by nguelfi           #+#    #+#              #
#    Updated: 2017/05/04 13:27:16 by nguelfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB_DIR = ./lib
SRC_DIR = ./src
INCLUDE = ./include
OBJ_DIR = ./obj

SRC = ft_make_list.c ft_check_file.c main.c
SRC_O = $(addprefix $(SRC_DIR)/,$(SRC))
BIN = ${SRC:%.c=%.o}
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

FLAGS = -Wall -Werror -Wextra
OFLAGS = -pipe -flto
LIBFT = $(LIB_DIR)/libft.a

all:
	@$(MAKE) -C $(LIB_DIR) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	gcc $(FLAGS) -I $(LIB_DIR) -I $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
##	gcc $(FLAGS) -I $(LIB_DIR) -I $(INCLUDE) -o $@ -c @<
	gcc $(FLAGS) $(OBJ) -L $(LIB_DIR) -lft -I $(INCLUDE) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all $(NAME)
