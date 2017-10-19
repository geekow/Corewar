# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/02 05:52:25 by jjaouen           #+#    #+#              #
#    Updated: 2017/10/07 04:47:39 by jjaouen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Werror -Wextra -g

NAME = ../asm

PATHOBJ = obj/

PATHSRC = src/

DEP = Makefile ./src/includes/op.h ./src/includes/asm.h ../libft/libft.a

HEAD = ./src/includes/

SRC = asm.c \
			get_label_vle.c \
			write.c \
			encode.c \
			op.c \
			header.c \
			parser.c \
			check_validity.c \
			error.c \
			debug.c \
			header_utils.c \
			check_validity_2.c \
			free.c \
			utils.c \
			error_2.c \

LIB = ../libft/libft.a

OBJ = $(patsubst %.c,$(PATHOBJ)/%.o,$(SRC))

all: $(NAME)

$(PATHOBJ):
	@mkdir -p obj

$(LIB):
	@make -C ../libft/

$(NAME): $(DEP) $(LIB) $(addprefix $(PATHSRC)/,$(SRC)) $(PATHOBJ) $(OBJ)
	@make -C ../libft/
	@$(GCCF) $(OBJ) $(LIB) -I $(HEAD) -o $(NAME)
	@echo "Compil asm Ok"

$(PATHOBJ)/%.o: $(PATHSRC)/%.c
	@$(GCCF) -c $< -o $@

clean:
	@make clean -C ../libft/
	@rm -rf $(PATHOBJ)
	@echo "OBJ rm"

fclean: clean
	@make fclean -C ../libft/
	@rm -rf $(NAME)
	@echo "LIB & EXEC rm"

re: fclean all

.PHONY: all clean fclean re
