NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR		= src
INC_DIR		= inc
MLX_DIR		= minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lbsd

SRC = \
	main.c \
	mandelbrot.c \
	julia.c \
	draw.c \
	map.c \
	utils.c \
	fractol.c \
	hooks.c

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
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

party:
	@printf "\033c"
	@echo "\n\033[35m♪┏(・o･)┛♪"
	@sleep 1
	@printf "\033c"
	@echo "\033[1;33m♪┗(・o･)┓♪"
	@sleep 1
	@printf "\033c"
	@echo "\n\033[36m♪┏(・o･)┛♪"
	@sleep 1
	@printf "\033c"
	@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re party
