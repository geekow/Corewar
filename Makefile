# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 16:55:10 by jjaouen           #+#    #+#              #
#    Updated: 2017/10/07 11:39:03 by jjaouen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Werror -Wextra

NAME_VM = corewar

NAME_ASM = asm

PATHOBJVM = obj/obj_vm

PATHOBJASM = obj/obj_asm

PATHSRCVM = VM/srcs/

LIB = libft

PATHSRCASM = asm_dir/src/

SRCVM = main.c init_virtual_machine.c errors.c parse_params.c \
				get_player_info.c load_players.c load_battlefield.c \
				run_virtual_machine.c get_next_op.c op.c dump_battlefield.c \
				get_last_live_player.c op_1.c op_2.c op_3.c op_4.c op_5.c \
				op_6.c op_7.c op_8.c op_9.c op_10.c op_11.c op_12.c op_13.c \
				op_14.c op_15.c op_16.c utils.c op_args.c visualizer.c \
				op_args_2.c event.c audio.c reg.c \

SRCASM = asm.c \
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

LIB_ASM = ./libft/libft.a

LIB_VM = ./VM/libft/libft.a

PATH_H = -I VM/includes/

OBJVM = $(patsubst %.c,$(PATHOBJVM)/%.o,$(SRCVM))

OBJASM = $(patsubst %.c,$(PATHOBJASM)/%.o,$(SRCASM))

all: $(LIB_VM) $(LIB_ASM) $(NAME_VM) $(NAME_ASM)

$(PATHOBJVM):
	@mkdir -p obj
	@mkdir -p obj/obj_vm

libft: $(LIB_VM) $(LIB_ASM)
	@echo "Libft(s) OK"

$(PATHOBJASM):
	@mkdir -p obj
	@mkdir -p obj/obj_asm

$(LIB_ASM): 
	@make -C ./libft/

$(LIB_VM): 
	@make -C ./VM/libft/

$(NAME_VM): $(LIB_VM) $(addprefix $(PATHSRCVM)/,$(SRCVM)) $(PATHOBJVM) $(OBJVM)
	@$(GCCF) -lform -lncurses $(OBJVM) $(LIB_VM) -o $(NAME_VM)
	@echo "Compil VM Ok"

$(NAME_ASM) : $(LIB_ASM) $(addprefix $(PATHSRCASM)/,$(SRCASM)) $(PATHOBJASM) $(OBJASM)
	@$(GCCF) $(OBJASM) $(LIB_ASM) -o $(NAME_ASM)
	@echo "Compil ASM Ok"

$(PATHOBJVM)/%.o: $(PATHSRCVM)/%.c
	@$(GCCF) $(PATH_H) -c $< -o $@

$(PATHOBJASM)/%.o: $(PATHSRCASM)/%.c
	@$(GCCF) -c $< -o $@

clean:
	@make clean -C ./libft/
	@make clean -C ./VM/libft/
	@rm -rf $(PATHOBJVM) $(PATHOBJASM)
	@rm -rf obj
	@echo "OBJ rm"

fclean: clean
	@make fclean -C ./libft/
	@make fclean -C ./VM/libft/
	@rm -rf $(NAME_VM) $(NAME_ASM)
	@echo "LIB & EXEC rm"

re: fclean all

.PHONY: all clean fclean re
