# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 12:19:50 by luibarbo          #+#    #+#              #
#    Updated: 2024/06/13 12:40:08 by luibarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

INCLUDE	=	-I include
SRC_DIR	=	src/
OBJ_DIR	=	obj/
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

LIBFT	=	libft/libft.a

# COLORS
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
B_GREEN		=	\033[1;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

SRC_FILES	=	main.c operations.c parse_params.c push_a.c push_b.c \
		rev_rotate_operations.c rotate_operations.c sort_big_stack.c \
		sort_big_utils.c sort_big_utils2.c sort_three.c sorting_algorithm.c \
		sorting_utils.c swap_operations.c utils.c valid_params.c \

SRC	=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ	=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ_DIR) $(OBJ)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBFT)
	@echo "$(B_GREEN)$(NAME) created successfully!$(DEF_COLOR)"

 $(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

all : $(NAME)

clean :
	@make clean -C ./libft
	@$(RM) $(OBJ_DIR)
	@echo "$(CYAN)push_swap objects files cleaned!$(DEF_COLOR)"

fclean : clean
	@make fclean -C ./libft
	@$(RM) $(NAME)
	@echo "$(BLUE)$(NAME) cleaned!$(DEF_COLOR)"

re : fclean all
	@echo "$(GREEN)Cleaned and rebuilt $(NAME)!$(DEF_COLOR)"

.PHONY : all clean fclean re
