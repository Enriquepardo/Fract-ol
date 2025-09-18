NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR		= src
INC_DIR		= inc
MLX_DIR		= minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lbsd

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/mandelbrot.c $(SRC_DIR)/julia.c \
      $(SRC_DIR)/draw.c $(SRC_DIR)/map.c $(SRC_DIR)/utils.c \
      $(SRC_DIR)/fractol.c $(SRC_DIR)/hooks.c

OBJ = $(SRC:.c=.o)

all: $(MLX) $(NAME)

$(MLX):
	@echo "\033[36m--> compiling MiniLibX...\033[0m"
	@$(MAKE) -C $(MLX_DIR) all 


$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "\033[32m✔ $(NAME) successfully compiled\033[0m"

clean:
	@rm -f $(OBJ)
	@make -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@echo "\n\033[31mDeleting EVERYTHING!"

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
