/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:16:29 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/03 02:20:46 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_msg_678(t_virtual_machine *vm, t_process *process, t_arg *arg)
{
	if (vm->flags & FLAG_VERBOSE && vm->flag_verbose_value & 4 &&
	(!(vm->flags & FLAG_VISUALIZER)) && arg->error)
		ft_printf("P %4i | %s %d %d r%d\n", process->id,
		g_op_tab[(int)process->op].name, REV_MEM(arg->true_vle[0],
		REG_SIZE), REV_MEM(arg->true_vle[1], REG_SIZE), arg->vle[2]);
}

void	op_and(t_virtual_machine *vm, t_process *process)
{
	t_arg	*arg;
	int		error;

	error = 0;
	arg = ft_fill_args(vm, process);
	if (arg->type[2] == REG_CODE && arg->vle[2] > 0 &&
	arg->vle[2] <= REG_NUMBER && arg->error)
		process->reg[arg->vle[2] - 1] =
		ft_reverse_memory_int(ft_reverse_memory_int(arg->true_vle[0],
		REG_SIZE) & ft_reverse_memory_int(arg->true_vle[1],
		REG_SIZE), REG_SIZE);
	else
		error = 1;
	process->pc += g_op_tab[(int)process->op].octal +
	ft_convert_intptr(arg->size, g_op_tab[(int)process->op].ac) + 1;
	if (arg->error && error == 0 && process->reg[arg->vle[2] - 1] == 0 &&
	process->carry == 0)
		process->carry = 1;
	else if (arg->error && error == 0 &&
	process->reg[arg->vle[2] - 1] != 0 && process->carry == 1)
		process->carry = 0;
	process->pc = process->pc % MEM_SIZE;
	verbose_msg_678(vm, process, arg);
	ft_free_args(arg);
}
