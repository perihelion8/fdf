.PHONY: all clean fclean re

CC 			:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM 			:= rm -f

NAME 		:= fdf

SRC_DIR		:= src
OBJ_DIR		:= build

SRCS 		:= $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
OBJS 		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

GREEN 		:= \033[0;32m
RESET 		:= \033[0m

LIBFT_DIR	:=	libft
MLX_DIR		:=	mlx_linux

LIBFT		:=	$(LIBFT_DIR)/libft.a
MLX			:=	$(MLX_DIR)/libmlx_Linux.a

INCLUDES	:=	-I. -I$(LIBFT_DIR) -I$(MLX_DIR)

LDFLAGS  	:=	-L$(LIBFT_DIR) -lft \
				-L$(MLX_DIR) -lmlx_Linux \
				-L/usr/lib -lXext -lX11 -lm -lz

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(GREEN)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "$(GREEN)Linking executable...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@echo "$(GREEN)Building mlx...$(RESET)"
	$(MAKE) -C $(MLX_DIR)

clean:
	@echo "$(GREEN)Cleaning object files...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(GREEN)Removing executable...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
