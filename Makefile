LIB = ar rcs
RM = rm -f

CC = gcc

BLUE   = \033[34m
RESET  = \033[0m

CCFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = src

SRC = push_shap_ops1.c push_shap_ops2.c push_swap_prices.c \
	push_swap_stacks1.c push_swap_stacks2.c push_swap_utils.c \
	push_swap_moves.c push_swap_moves2.c push_swap.c

OBJ = $(SRC:.c=.o)

INCLUDE = push_swap.h

NAME = push_swap

LIBFTA = Helicopter/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CCFLAGS) -I/Helicopter/libft.h -c $< -o $@

$(NAME): $(OBJ)
	@cd Helicopter && make
	@$(CC) $(CCFLAGS) $(OBJ) -IHelicopter $(LIBFTA) -o $(NAME)
	@echo "$(BLUE)        ||>>    $(BLUE)push_swap compiled!!    <<||$(RESET)"

clean:
	@$(RM) $(OBJ)
	@cd Helicopter && make clean

fclean:
	@$(RM) $(NAME) $(OBJ)
	@cd Helicopter && make fclean

re: fclean all

.PHONY: all clean fclean re