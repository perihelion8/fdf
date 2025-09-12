NAME		:=	fdf

CC			:=	cc
CFLAGS		:=	-Wall -Werror -Wextra

OBJ_DIR		:=	obj
LIBFT_DIR	:=	libft
GNL_DIR		:=	get_next_line
MLX_DIR		:=	mlx_linux

SRC      	:=	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				main.c parser.c project_iso.c draw.c handle_key.c xmalloc.c free.c
OBJ      	:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT		:=	$(LIBFT_DIR)/libft.a
MLX			:=	$(MLX_DIR)/libmlx_Linux.a

INCLUDES	:=	-I. -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(GNL_DIR)

LDFLAGS  	:=	-L$(LIBFT_DIR) -lft \
				-L$(MLX_DIR) -lmlx_Linux \
				-L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
		$(CC) $(OBJ) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.c fdf.h
		mkdir -p $(dir $@)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(MLX):
		$(MAKE) -C $(MLX_DIR)

clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(MLX_DIR) clean
		rm -rf $(OBJ_DIR)

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
