NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = gcc


SRC = ft_printf_utils.c ft_printf.c
OBJ = $(patsubst %.c, %.o, $(SRC))

RESET  = \033[0
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m

all : $(NAME)

$(NAME) : $(OBJ) Makefile ft_printf.h
	@echo "$(GREEN)All done!$(RESET)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o : %.c
	@echo "$(YELLOW)Creating objects...$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@echo "$(RED)Deleting objects...$(RESET)"
	@rm -rf $(OBJ)

fclean : clean
	@echo "$(RED)Deleting library...$(RESET)"
	@rm -rf $(NAME)

re : fclean $(NAME)


.PHONY : all clean fclean re