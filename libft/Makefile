# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 11:54:05 by luibarbo          #+#    #+#              #
#    Updated: 2024/06/11 10:30:35 by luibarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDE	=	-I include
SRC_DIR	=	src/
OBJ_DIR	=	obj/
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -rf

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


SRC_FILES =	ft_isalpha ft_isdigit ft_isalnum ft_isascii \
	ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy \
	ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower \
	ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp \
	ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr \
	ft_strjoin ft_strtrim ft_putchar_fd ft_putstr_fd \
	ft_putendl_fd ft_split ft_itoa ft_putnbr_fd ft_strmapi \
	ft_striteri ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
	ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter \
	ft_lstmap \
	ft_printf ft_putchar_pf ft_putstr_pf ft_putnbr_pf \
	ft_putnbr_unsigned_pf ft_puthexa_pf ft_putpointer_pf \
	get_next_line get_next_line_utils \

SRC	=	${addprefix ${SRC_DIR}, ${addsuffix .c, ${SRC_FILES}}}

OBJ	=	${SRC:${SRC_DIR}%.c=$(OBJ_DIR)%.o}

${OBJ_DIR}%.o : ${SRC_DIR}%.c
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${NAME} : ${OBJ_DIR} ${OBJ}
	@${AR} ${NAME} ${OBJ}
	@echo "$(GREEN)${NAME} created successfully!$(DEF_COLOR)"

${OBJ_DIR} :
	@mkdir -p ${OBJ_DIR}

all : ${NAME}

clean :
	@${RM} ${OBJ_DIR}
	@echo "$(CYAN)libft objects files cleaned!$(DEF_COLOR)"

fclean : clean
	@${RM} ${NAME}
	@echo "$(BLUE)${NAME} cleaned!$(DEF_COLOR)"

re : fclean all
	@echo "$(GREEN)Cleaned and rebuilt libft!$(DEF_COLOR)"

.PHONY : all clean fclean re
