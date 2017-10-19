/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 20:32:33 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/07 03:56:37 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "ft_printf.h"
# include "op.h"

# define REV_MEM		ft_reverse_memory_int
# define REG			process->reg
# define VLE_SBS		vm->flag_sbs_value

# define FLAG_DUMP			1
# define FLAG_VERBOSE		2
# define FLAG_VISUALIZER	4
# define FLAG_STEPBYSTEP	8
# define FLAG_AFF			16
# define FLAG_AUDIO			32
# define TURBO				1

typedef	struct		s_arg
{
	int				*type;
	int				*size;
	int				*vle;
	int				*true_vle;
	int				error;
}					t_arg;

typedef struct		s_player
{
	int				id;
	char			*path;
	unsigned char	name[PROG_NAME_LENGTH + 1];
	unsigned char	comment[COMMENT_LENGTH + 1];
	unsigned char	code[CHAMP_MAX_SIZE];
	int				prog_size;
	int				exec_magic;
	int				pc_address;
	int				last_live_cycle;
}					t_player;

typedef struct		s_process
{
	int				id;
	int				fatherid;
	int				carry;
	int				reg[REG_NUMBER];
	int				pc;
	int				op_wait;
	int				live_counter;
	int				last_live;
	char			op;
}					t_process;

typedef struct		s_virtual_machine
{
	unsigned int	flags;
	int				flag_dump_value;
	int				flag_verbose_value;
	int				flag_sbs_value;
	int				nb_player;
	int				process_counter;
	int				turn_counter;
	int				check_counter;
	int				ctd_counter;
	int				ctd;
	int				lives_in_cycle;
	int				colorsid[MEM_SIZE];
	char			colors[MEM_SIZE];
	char			battlefield[MEM_SIZE];
	t_player		players[MAX_PLAYERS];
	t_list			*processes;
}					t_virtual_machine;

/*
**	VM
*/

void				dump_battlefield(t_virtual_machine *vm);
void				write_error(char *str);
void				write_usage(void);
void				parse_params(int ac, char **av, t_virtual_machine *vm,
																		int i);
void				get_player_info(t_virtual_machine *vm, char *path, int *id);
void				get_next_op(t_virtual_machine *vm, t_process *process);
void				load_players(t_virtual_machine *vm);
void				load_battlefield(t_virtual_machine *vm);
void				run_virtual_machine(t_virtual_machine *vm);
int					get_last_live_player(t_virtual_machine *vm);
int					init_virtual_machine(t_virtual_machine *vm);
int					is_player_id(t_virtual_machine *vm, int id);
void				op_live(t_virtual_machine *vm, t_process *process);
void				op_ld(t_virtual_machine *vm, t_process *process);
void				op_st(t_virtual_machine *vm, t_process *process);
void				op_add(t_virtual_machine *vm, t_process *process);
void				op_sub(t_virtual_machine *vm, t_process *process);
void				op_and(t_virtual_machine *vm, t_process *process);
void				op_or(t_virtual_machine *vm, t_process *process);
void				op_xor(t_virtual_machine *vm, t_process *process);
void				op_zjmp(t_virtual_machine *vm, t_process *process);
void				op_ldi(t_virtual_machine *vm, t_process *process);
void				op_sti(t_virtual_machine *vm, t_process *process);
void				op_fork(t_virtual_machine *vm, t_process *process);
void				op_lld(t_virtual_machine *vm, t_process *process);
void				op_lldi(t_virtual_machine *vm, t_process *process);
void				op_lfork(t_virtual_machine *vm, t_process *process);
void				op_aff(t_virtual_machine *vm, t_process *process);
void				visualizer(t_virtual_machine *vm);
void				init_visualizer(void);
void				free_lst(t_list *list);

/*
**	Parse ac in reg.c
*/

void				reg_dump(int ac_verif, char *next_av,
t_virtual_machine *vm);
void				reg_verbose(int ac_verif, char *next_av,
t_virtual_machine *vm);
void				reg_player_with_id(int ac_verif, char **av,
t_virtual_machine *vm);
void				reg_sbs(int ac_verif, char *next_av,
t_virtual_machine *vm);

/*
**	Manage op_args
*/

t_arg				*ft_fill_args(t_virtual_machine *vm, t_process *process);
int					*ft_get_tabtype(t_virtual_machine *vm, t_process *process);
int					*ft_get_tabsize(int *type, t_process *process);
void				ft_get_tabvle(t_virtual_machine *vm, t_process *process,
									t_arg *arg);
void				ft_free_args(t_arg *arg);
int					nb_process_and_clear(int i);

/*
**	Utils
*/

int					ft_reverse_memory_int(int vle, int size);
int					ft_convert_intptr(int *tab, int len);
void				ft_verbose(t_virtual_machine *vm, t_process *process,
								t_arg *arg);
int					ft_fix_neg_adrr(int pos);
int					ft_read_cbc(t_virtual_machine *vm, int pc, int size);

/*
**	verbose_msg is declared in op_5 and used in op_6, 7 and 8.
*/
void				verbose_msg_678(t_virtual_machine *vm, t_process *process,
																	t_arg *arg);

/*
**	Manage Event
*/

void				ft_event_sbs(t_virtual_machine *vm);
void				ft_event_pause(void);
void				ft_audio_welcome(void);
int					ft_audio_close(t_virtual_machine *vm);
void				ft_audio_kill_process(t_virtual_machine *vm);

#endif
