NAME = pushswap
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SRCS_DIR = ./
OBJS_DIR = objs/

SRCS_FILE = push_swap list_creation
SRCS = $(addprefix $(SRCS_DIR),$(addsuffix .c,$(SRCS_FILE)))
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

#BONUS_FILE = 
#BONUS = $(addprefix $(SRCS_DIR),$(addsuffix .c,$(BONUS_FILE)))
#BOBJS = $(BONUS:.c=.o)

YELLOW = \033[33m
MAGENTA = \033[35m
RED = \033[31m
RESET = \033[0m

all: $(OBJS_DIR) $(LIBFT) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@$(MAKE) -C libft

# %.o: %.c
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -I$(SRCS_DIR) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@echo "Linking .o files and libft to create $(YELLOW)push_swap$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

#bonus: $(OBJS) $(BOBJS)
#	@echo "Archiving srcs & bonus files in $(YELLOW)push_swap$(RESET)"
#	@ar rcs $(NAME) $(OBJS) $(BOBJS)

clean:
	@if [ -d $(OBJS_DIR) ]; then \
		echo "Removing object files in $(YELLOW)push_swap$(RESET)"; \
		rm -rf $(OBJS_DIR); \
	else \
		echo "$(RED)No object files to remove in $(RESET)push_swap"; \
	fi
	@make -C libft clean

fclean: clean
	@if [ -f $(NAME) ]; then \
		echo "Removing $(MAGENTA)$(NAME)$(RESET)"; \
		rm -f $(NAME); \
	else \
		echo "$(RED)No $(RESET)$(NAME) $(RED)to remove$(RESET)"; \
	fi
	@make -C libft fclean

re: fclean all bonus

.PHONY: all bonus clean fclean re