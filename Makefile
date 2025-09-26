.PHONY: all clean fclean re

NAME 		:=	fdf

CC 			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
RM 			:=	rm -rf

SRC_DIR		:=	src
OBJ_DIR		:=	build

SRCS 		:=	$(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
OBJS 		:=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

LIBFT_DIR	:=	libft
MLX_DIR		:=	mlx_linux

LIBFT		:=	$(LIBFT_DIR)/libft.a
MLX			:=	$(MLX_DIR)/libmlx_Linux.a

INCLUDES	:=	-Iinclude -I$(LIBFT_DIR) -I$(MLX_DIR)

LDFLAGS  	:=	-L$(LIBFT_DIR) -lft \
				-L$(MLX_DIR) -lmlx_Linux \
				-L/usr/lib -lXext -lX11 -lm -lz

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
