NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs/
OBJS_DIR = objs/

LIBFT_SRCS_FILE = isalpha isdigit isalnum isascii isprint strlen memset bzero memcpy memmove strlcpy strlcat \
toupper tolower strchr strrchr strncmp memchr memcmp strnstr atoi calloc strdup substr strjoin strtrim split \
itoa strmapi striteri putchar_fd putstr_fd putendl_fd putnbr_fd
LIBFT_SRCS = $(addprefix $(SRCS_DIR)ft_,$(addsuffix .c,$(LIBFT_SRCS_FILE)))
LIBFT_OBJS = $(LIBFT_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

PRINTF_SRCS_FILE = ft_printf print_p printf_putchar printf_putstr printf_strlen putnbr_pointer putnbr_unsigned putnbr
PRINTF_SRCS = $(addprefix $(SRCS_DIR),$(addsuffix .c,$(PRINTF_SRCS_FILE)))
PRINTF_OBJS = $(PRINTF_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

OBJS = $(LIBFT_OBJS) $(PRINTF_OBJS)

BONUS_FILE = lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap 
BONUS = $(addprefix $(SRCS_DIR)ft_,$(addsuffix .c,$(BONUS_FILE)))
BOBJS = $(BONUS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

YELLOW = \033[33m
MAGENTA = \033[35m
RED = \033[31m
RESET = \033[0m

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# %.o: %.c
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -I$(SRCS_DIR) -c $< -o $@

$(NAME): $(OBJS) $(BOBJS)
	@echo "Archiving srcs & bonus files in $(YELLOW)libft$(RESET)"
	@ar rcs $(NAME) $(OBJS) $(BOBJS)

#bonus: $(OBJS) $(BOBJS)
#	@echo "Archiving srcs & bonus files in $(YELLOW)libft$(RESET)"
#	@ar rcs $(NAME) $(OBJS) $(BOBJS)

clean:
	@if [ -d $(OBJS_DIR) ]; then \
		echo "Removing object files in $(YELLOW)libft$(RESET)"; \
		rm -rf $(OBJS_DIR); \
	else \
		echo "$(RED)No object files to remove in $(RESET)libft"; \
	fi

fclean:
	@if [ -f $(NAME) ]; then \
		echo "Removing $(MAGENTA)$(NAME)$(RESET)"; \
		rm -f $(NAME); \
	else \
		echo "$(RED)No $(RESET)$(NAME) $(RED)to remove$(RESET)"; \
	fi

re: fclean all bonus

.PHONY: all clean fclean re bonus