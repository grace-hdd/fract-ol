# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 14:36:43 by grhaddad          #+#    #+#              #
#    Updated: 2025/11/07 14:17:56 by grhaddad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m
RESET	= \033[0m
BOLD	= \033[1m

NAME		= fractol
CC			= cc
CFLAGS		= -Wextra -Wall -Werror -g -O2
MLXFLAGS	= -L./mlx -lmlx -lXext -lX11 -lm
RM			= rm -rf

SRC_PATH	= src/
OBJ_PATH	= obj/
INC_PATH	= includes/

SOURCES		= main.c \
		  init.c \
		  init_utils.c \
		  render.c \
		  render_utils.c \
		  events.c \
		  math_utils.c \
		  string_utils.c \
		  fractal_sets.c \
		  colors.c \
		  color_utils.c \
		  julia.c \
		  complex_math.c

SRCS		= $(addprefix $(SRC_PATH), $(SOURCES))
OBJS		= $(addprefix $(OBJ_PATH), $(SOURCES:.c=.o))
DEPS		= $(OBJS:.o=.d)

# Progress bar variables
TOTAL_FILES	= $(words $(SOURCES))
CURRENT		= 0

.PHONY: all bonus clean fclean fclean_all re norm help mlx

all: banner mlx $(NAME) success

mlx: mlx/libmlx.a

mlx/libmlx.a:
	@echo "$(YELLOW)$(BOLD)Compiling MLX library...$(RESET)"
	@make -C mlx
	@echo "$(GREEN)✓ MLX library compiled!$(RESET)"

$(NAME): $(OBJ_PATH) $(OBJS)
	@echo "$(YELLOW)$(BOLD)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)✓ $(NAME) compiled successfully!$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@$(eval CURRENT=$(shell echo $$(($(CURRENT)+1))))
	@echo "$(CYAN)Compiling [$(CURRENT)/$(TOTAL_FILES)]: $(PURPLE)$<$(RESET)"
	@$(CC) $(CFLAGS) -MMD -MP -I$(INC_PATH) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@echo "$(RED)$(BOLD)Cleaning object files...$(RESET)"
	@$(RM) $(OBJ_PATH)
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)$(BOLD)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ $(NAME) removed!$(RESET)"

fclean_all: fclean
	@echo "$(RED)$(BOLD)Cleaning MLX library...$(RESET)"
	@make -C mlx clean
	@echo "$(GREEN)✓ MLX library cleaned!$(RESET)"

re: fclean all

norm:
	@echo "$(YELLOW)$(BOLD)Checking norminette...$(RESET)"
	@norminette $(SRCS) $(INC_PATH) || true

help:
	@echo "$(BOLD)$(BLUE)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)       - Build the project"
	@echo "  $(GREEN)clean$(RESET)     - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)    - Remove object files and executable"
	@echo "  $(GREEN)fclean_all$(RESET) - Remove object files, executable and MLX library"
	@echo "  $(GREEN)re$(RESET)        - Rebuild the project"
	@echo "  $(GREEN)norm$(RESET)      - Check code with norminette"
	@echo "  $(GREEN)help$(RESET)      - Show this help message"

banner:
	@echo "$(BOLD)$(PURPLE)"
	@echo "███████╗██████╗  █████╗  ██████╗████████╗██████╗ ██╗     "
	@echo "██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██║     "
	@echo "█████╗  ██████╔╝███████║██║        ██║   ██║   ██║██║     "
	@echo "██╔══╝  ██╔══██╗██╔══██║██║        ██║   ██║   ██║██║     "
	@echo "██║     ██║  ██║██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗"
	@echo "╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝"
	@echo "$(RESET)"
	@echo "$(BOLD)$(CYAN)Building fract'ol - Fractal Explorer$(RESET)"
	@echo "$(YELLOW)Author: $(WHITE)grace-hdd$(RESET)"
	@echo "$(YELLOW)Version: $(WHITE)1.0$(RESET)"
	@echo ""

success:
	@echo ""
	@echo "$(BOLD)$(GREEN)🎉 Build completed successfully! 🎉$(RESET)"
	@echo "$(YELLOW)Usage:$(RESET)"
	@echo "  $(CYAN)./$(NAME) mandelbrot$(RESET)"
	@echo "  $(CYAN)./$(NAME) julia <real> <imaginary>$(RESET)"
	@echo "  $(CYAN)./$(NAME) burning_ship$(RESET)"
	@echo ""

# Include dependencies
-include $(DEPS)