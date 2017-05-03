
NAME = fillit
LIB_DIR = ./lib
SRC_DIR = ./src
OBJ_DIR = ./obj
INCLUDE = ./include

SRC = ft_make_list.c ft_check_file.c main.c
OBJ = $(addprefix $(SRC_DIR)/,$(SRC))
BIN = ${SRC:%.c=%.o}

FLAGS = -Wall -Werror -Wextra
LIBFT = $(LIB_DIR)/libft.a

all:
	mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(FLAGS) $(OBJ) -c -o $@ $<

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all $(NAME)
