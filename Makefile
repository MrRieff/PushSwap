# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lualbuqu <lualbuqu@42.student.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 13:18:07 by lualbuqu          #+#    #+#              #
#    Updated: 2024/08/28 19:40:02 by lualbuqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME = push_swap

# Source Directory
SRC_DIR = src/
OBJ_DIR = objs/

ALGORITHM_DIR = $(SRC_DIR)Algorithm/sort_stacks.c\
				$(SRC_DIR)Algorithm/sort_three.c\
				$(SRC_DIR)Algorithm/is_sorted.c
				

INITIALIZER_DIR = $(SRC_DIR)Init/init_a.c\
				  $(SRC_DIR)Init/init_b.c\
				  $(SRC_DIR)Init/init_stack.c

MOVES_DIR = $(SRC_DIR)Moves/rotate.c\
			$(SRC_DIR)Moves/rev_rotate.c\
			$(SRC_DIR)Moves/swap.c\
			$(SRC_DIR)Moves/push.c\
			$(SRC_DIR)Moves/operations.c

UTILS_DIR = $(SRC_DIR)Utils/utils.c\
			$(SRC_DIR)Utils/utils2.c

ERROR_DIR = $(SRC_DIR)Error/handle_error.c

MAIN_DIR = $(SRC_DIR)push_swap.c


# Sources (files to add)
SRCS = $(MOVES_DIR) $(ERROR_DIR) $(ALGORITHM_DIR) $(INITIALIZER_DIR) $(MAIN_DIR) $(UTILS_DIR)
OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

# Remove files
RM = rm -f

RM_F = rm -rf

# Reset and effects
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
UNDERLINE = \033[4m
BLINK = \033[5m
INVERT = \033[7m

# Standard colors
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

# Transform into object files
# OBJS = $(SRCS:.c=.o)

# Create executable from object files
$(NAME): $(OBJS)
	@echo "$(BOLD)$(YELLOW)LINKING OBJECTS...$(RESET)\n"
	@$(CC) $(OBJS) -o $(NAME) || { echo "$(BOLD)$(RED)ERROR: LINKING FAILED$(RESET)"; exit 1; }
	@echo "$(BOLD)$(GREEN)$(NAME) CREATED SUCCESSFULLY$(RESET)\n"

# COMMANDS

all: $(NAME)

run: re clean
	@echo "$(BOLD)$(YELLOW)RUNNING $(NAME)...$(RESET)\n"
	@clear
	@echo "$(BOLD)$(CYAN)Output:\n$(RESET)"
	@./$(NAME) || { echo "$(BOLD)$(RED)ERROR: EXECUTION FAILED$(RESET)"; exit 1; }
	@echo "\n\n\n$(BOLD)$(GREEN)$(NAME) WAS EXECUTED SUCCESSFULLY$(RESET)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(BOLD)$(YELLOW)COMPILING $<...$(RESET)\n"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ || { echo "$(BOLD)$(RED)ERROR: COMPILATION FAILED FOR $<$(RESET)"; exit 1; }

clean:
	@echo "$(BOLD)$(YELLOW)CLEANING OBJECTS...$(RESET)\n"
	@$(RM) $(OBJS) || { echo "$(BOLD)$(RED)ERROR: CLEANING OBJECTS FAILED$(RESET)"; exit 1; }
	@echo "$(BOLD)$(CYAN)CLEANED OBJECT FILES$(RESET)\n"

fclean: clean
	@echo "$(BOLD)$(YELLOW)CLEANING ALL FILES...$(RESET)\n"
	@$(RM) $(NAME) || { echo "$(BOLD)$(RED)ERROR: CLEANING ALL FILES FAILED$(RESET)"; exit 1; }
	@$(RM_F) $(OBJ_DIR)*.
	@echo "$(BOLD)$(CYAN)CLEANED ALL FILES$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
