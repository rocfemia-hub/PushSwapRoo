LIB = ar rcs
RM = rm -f

CC = cc

RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
RESET  = \033[0m

CCFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = src

SRC = push_shap_ops1.c push_shap_ops2.c push_swap_prices.c \
	push_swap_stacks.c push_swap_utils.c push_swap.c

OBJ = $(SRC:.c=.o)

INCLUDE = push_swap.h

NAME = push_swap

LIBFTA = Helicoptero/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CCFLAGS) -I/Helicoptero/libft.h -I/usr/include -O3 -c $< -o $@

$(NAME): $(OBJ)
	@cd Helicoptero && make
	@$(CC) $(CCFLAGS) $(OBJ) -IHelicoptero $(LIBFTA) -o $(NAME)
	@echo "$(YELLOW)        ||>>    $(BLUE)push_swap $(YELLOW)compiled!!    <<||$(RESET)"

clean:
	@$(RM) $(OBJ)
	@cd Helicoptero && make clean

fclean:
	@$(RM) $(NAME) $(OBJ)
	@cd Helicoptero && make fclean

re: fclean all

.PHONY: all clean fclean re