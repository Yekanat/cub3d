NAME = cub3D

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[0;33m
RESET = \033[0m

LIBFT = libft/libft.a
MLX_FOLDER = minilibx-linux
MLX = $(MLX_FOLDER)/libmlx.a

CFLAGS = -Wall -Wextra -Werror -g -O3
INC = -I./$(MLX_FOLDER) -I./libft -I./includes
LIB = -L./$(MLX_FOLDER) -lmlx -lXext -lX11 -lm -lz -L./libft/ -lft
SRCDIR = srcs
OBJDIR = obj

SOURCES = \
	events/doors.c \
	events/hooks.c \
	events/mouse_mouvement.c \
	events/move.c \
	events/torch.c \
	lines.c \
	main.c \
	mlx_utils/img_utils2.c \
	mlx_utils/img_utils.c \
	mlx_utils/mlx_utils.c \
	parsing/add_style.c \
	parsing/check_map_data.c \
	parsing/free_map.c \
	parsing/list_to_map.c \
	parsing/map_is_valid.c \
	parsing/open_file.c \
	parsing/parsing_utils.c \
	parsing/read_file.c \
	raycasting/raycasting.c \
	raycasting/raycasting_utils.c \
	render/color.c \
	render/minimap.c \
	render/render_background.c \
	render/render_walls.c \
	utils/clamp.c \
	utils/ft_puterror.c \
	utils/ft_strchrs.c \
	utils/line_dup.c

OBJS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

# Regola di compilazione principale
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@cc $(FLAGS) $(OBJS) -o $(NAME) $(INC) $(LIB)
	@echo "$(GREEN)Compilation finished successfully!$(RESET)"

# Compila la libreria Libft
$(LIBFT):
	@echo "$(GREEN)Building Libft...$(RESET)"
	@make -s -C libft libft.a

# Compila la libreria MinilibX
$(MLX):
	@echo "$(GREEN)Building minilibx...$(RESET)"
	@make -s -C $(MLX_FOLDER) all

# Regola per la compilazione degli oggetti
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@cc $(FLAGS) $(INC) -c $< -o $@

# Verifica la conformità alla Norminette
norm:
	@echo "$(YELLOW)Lancio norminette...$(RESET)"
	@norminette | grep "Error" > norm_errors.log || true
	@if [ -s norm_errors.log ]; then \
		err_count=$$(wc -l < norm_errors.log); \
		echo "$(RED)$$err_count erreur(s) détectée(s) :$(RESET)"; \
		cat norm_errors.log; \
	else \
		echo "$(GREEN)OK - Aucun problème détecté par la norminette.$(RESET)"; \
	fi
	@rm -f norm_errors.log

# Pulisce i file oggetto
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)
	@make -s -C libft clean
	@make -s -C $(MLX_FOLDER) clean

# Pulisce tutto, incluso l'eseguibile
fclean: clean
	@echo "$(RED)Cleaning all...$(RESET)"
	@rm -f $(NAME) $(LIBFT) $(MLX)

# Ricompila tutto
re: fclean all

.PHONY: all clean fclean re norm
