# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 20:00:00 by jjacobi           #+#    #+#              #
#    Updated: 2017/10/07 04:41:25 by jjaouen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ../corewar

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

SRC_FILES	= main.c init_virtual_machine.c errors.c parse_params.c \
				get_player_info.c load_players.c load_battlefield.c \
				run_virtual_machine.c get_next_op.c op.c dump_battlefield.c \
				get_last_live_player.c op_1.c op_2.c op_3.c op_4.c op_5.c \
				op_6.c op_7.c op_8.c op_9.c op_10.c op_11.c op_12.c op_13.c \
				op_14.c op_15.c op_16.c utils.c op_args.c visualizer.c \
				op_args_2.c event.c audio.c reg.c \

OBJ			= $(SRC_FILES:.c=.o)

H_DIRS		= -I ./includes -I ./libft/includes
OBJ_PATH	= ./obj
SRC_FOLDER	= ./srcs
LIBFT_PATH	= ./libft

OBJ = $(patsubst %.c,$(OBJ_PATH)/%.o,$(SRC_FILES))

GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m

ifeq ($(shell uname),Darwin)
	ECHO	= echo
else
	ECHO	= echo -e
endif

all: $(NAME)

$(OBJ_PATH):
	@mkdir -p obj

$(NAME): $(addprefix $(SRC_FOLDER)/,$(SRC_FILES)) $(OBJ_PATH) $(OBJ)
	@$(ECHO) "\r$(GREEN) The .o from $(NAME) are compiled.            \
		$(DEFAULT)"
	@($(MAKE) -C $(LIBFT_PATH))
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_PATH)/libft.a $(H_DIRS) -o $(NAME) \
		-lform -lncurses
	@$(ECHO) "$(GREEN)$(NAME)$(DEFAULT) created."

$(OBJ_PATH)/%.o: $(SRC_FOLDER)/%.c
	@$(ECHO) "\r$(GREEN) Compiling $<                      \c\033[K"
	@$(CC) $(CFLAGS) -c $< -o $@ $(H_DIRS)

clean:
	@rm -rf obj
	@$(ECHO) "All $(RED).o$(DEFAULT) are now deleted for $(NAME)."
	@($(MAKE) -C $(LIBFT_PATH) $@)

fclean:
	@rm -rf obj $(NAME)
	@$(ECHO) "All $(RED).o$(DEFAULT) are now deleted for $(NAME)."
	@$(ECHO) "$(RED)$(NAME)$(DEFAULT) is now deleted."
	@($(MAKE) -C $(LIBFT_PATH) $@)

re: fclean all

.PHONY: clean fclean re all
