NAME = push_swap
NAME_BONUS = checker

INC_DIR = ./inc
OBJS_DIR = ./obj
OBJS_BONUS_DIR = ./obj/bonus
SRC_DIR = ./src
BONUS_DIR = ./bonus

CC = gcc
CFLAGS = -I$(INC_DIR) -Wall -Werror -Wextra -fsanitize=address -g3

RM = rm -rf

OBJS = $(OBJS_DIR)/check_arguments.o \
		$(OBJS_DIR)/choose_method.o \
		$(OBJS_DIR)/ft_split.o \
		$(OBJS_DIR)/get_best_target.o \
		$(OBJS_DIR)/get_cost.o \
		$(OBJS_DIR)/list_functions.o \
		$(OBJS_DIR)/move_nodes_to_head.o \
		$(OBJS_DIR)/push_swap.o \
		$(OBJS_DIR)/rotate_nodes.o \
		$(OBJS_DIR)/swap_push_nodes.o \
		$(OBJS_DIR)/turk_algorithm.o \
		$(OBJS_DIR)/update_index.o \
		$(OBJS_DIR)/utils.o \
		$(OBJS_DIR)/validate_argvs.o

OBJS_BONUS = $(OBJS_BONUS_DIR)/check_arguments.o \
			$(OBJS_BONUS_DIR)/check_orders.o \
			$(OBJS_BONUS_DIR)/checker.o \
			$(OBJS_BONUS_DIR)/ft_split.o \
			$(OBJS_BONUS_DIR)/gnl_utils.o \
			$(OBJS_BONUS_DIR)/list_functions.o \
			$(OBJS_BONUS_DIR)/rotate_nodes.o \
			$(OBJS_BONUS_DIR)/swap_push_nodes.o \
			$(OBJS_BONUS_DIR)/update_index.o \
			$(OBJS_BONUS_DIR)/utils.o \
			$(OBJS_BONUS_DIR)/validate_argvs.o

GREEN = \033[0;32m
BOLD = \033[1m
GRAY = \033[0;90m
TEST = \033[0;95m

.PHONY: clean all fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN)Compilation finished.\n→ You can find the push_swap executable in $(BOLD)bin\n"

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	@echo "$(GRAY)Compiling file  →   $(shell echo $< | awk -F / '{print $$2}')"
	@mkdir -p $(OBJS_DIR)
	@$(CC) -c -MD $(CFLAGS) $< -o $@
-include $(OBJS_DIR)/*.d

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "\n$(GREEN)Bonus compilation finished.\n"

$(OBJS_BONUS_DIR)/%.o : $(BONUS_DIR)/%.c
	@echo "$(GRAY)Compiling bonus file  →   $(shell echo $< | awk -F / '{print $$2}')"
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_BONUS_DIR)
	@$(CC) -c -MD $(CFLAGS) $< -o $@
-include $(BONUS_DIR)/*.d

clean:
	@echo "\n$(TEST)Deleting $(OBJS_DIR)  ...\n"
	@$(RM) $(OBJS_DIR) 

fclean: clean
	@echo "$(TEST)Deleting $(NAME)  ...\n"
	@$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
