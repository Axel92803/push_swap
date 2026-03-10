NAME				= push_swap

LIBFT				= ./submodule_utils/libft/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

CC = cc

CFLAGS = -Wall -Wextra -Wpadded -g3 -I

RM = rm -f

CMD_DIR		=	$(SRC_DIR)cmd/push.c \
						$(SRC_DIR)cmd/rev_rotate.c \
						$(SRC_DIR)cmd/rotate.c \
						$(SRC_DIR)cmd/swap.c \

PS_DIR		=	$(SRC_DIR)init/disorder.c \
						$(SRC_DIR)init/stack_init.c \
						$(SRC_DIR)parse/parse.c \
						$(SRC_DIR)parse/parse_index.c \
						$(SRC_DIR)utils/error.c \
						$(SRC_DIR)utils/indexing.c \
						$(SRC_DIR)utils/utils.c \
						$(SRC_DIR)push_swap.c \

SRCS 				= $(CMD_DIR) $(PS_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
					@make all

$(LIBFT):
					@make all -C ./submodule_utils/libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)
					@echo "Push_swap compiled successfully"

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./submodule_utils/libft
					@echo "Cleaned push_swap .o files"

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@echo "Removed libft.a"
					@echo "Removed push_swap executable"

re: 				fclean all

.PHONY: 			start all clean fclean re
