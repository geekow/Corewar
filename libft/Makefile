# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 17:09:25 by jjaouen           #+#    #+#              #
#    Updated: 2017/06/06 00:53:21 by jjaouen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Werror -Wextra -g

NAME = libft.a

HEAD = libft.h

DEP = ./Makefile ./libft.h

SRC = ft_memset.c \
	ft_free_gnl.c \
	ft_strtrim_all.c \
	ft_free_words_tables.c \
	ft_tablen.c \
	ft_dprintf.c \
	ft_atoi_long.c \
	ft_print_words_tables.c \
	ft_memallocexit.c \
	ft_replace_char.c \
	ft_atoi_imt.c \
	ft_move_char_right.c \
	get_next_line.c \
	ft_itoa_base.c \
	ft_itoa_base_imt.c \
	ft_itoa_base_uimt.c \
	ft_itoa_imt.c \
	ft_itoa_uimt.c \
	ft_atoi_base.c \
	ft_strsubf.c \
	ft_strjoinf.c \
	ft_strchrint.c \
	ft_lstadd_end.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memchr.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_swap.c \
	ft_range.c \
	ft_is_sort.c \
	ft_count_if.c \
	ft_strmaj.c \
	ft_count_list.c \
	ft_sqrt.c \
	ft_print_words_tables.c \
	ft_utils_core.c \
	ft_utils_char.c \
	ft_modify_s.c \
	ft_modify_c.c \
	ft_utils_integer.c \
	ft_addchar.c \
	ft_apply_attribut_int.c \
	ft_apply_flagmin.c \
	ft_modify_int.c \
	ft_parse.c \
	ft_printf.c


OBJ = $(SRC:.c=.o)

all: $(DEP) $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Libft.a created"

%.o: %.c
	@$(GCCF) -c $<

clean:
	@rm -f $(OBJ)
	@echo "rm OBJ libft"

fclean: clean
	@rm -rf $(NAME)
	@echo "rm libft.a"

re: fclean all

.PHONY:clean
