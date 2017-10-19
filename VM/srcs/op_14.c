/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_14.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:16:59 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/03 03:02:39 by drimo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		op_lldi_finish(t_virtual_machine *vm, t_process *process,
											t_arg *arg, int *argu)
{
	if (vm->flags & FLAG_VERBOSE && vm->flag_verbose_value & 4 &&
	(!(vm->flags & FLAG_VISUALIZER)) && arg->error)
		ft_printf("P %4i | %s %d %d r%d\n%7s| -> load from %d + %d = %d \
(with pc %d)\n", process->id,
		g_op_tab[(int)process->op].name, argu[0], argu[1], arg->vle[2], "",
		argu[0], argu[1], (argu[0] + argu[1]), argu[2]);
	ft_free_args(arg);
}

void		op_lldi_pc(t_process *process, t_arg *arg)
{
	process->pc += g_op_tab[(int)process->op].octal +
	ft_convert_intptr(arg->size, g_op_tab[(int)process->op].ac) + 1;
	process->pc = process->pc % MEM_SIZE;
}

void		op_lldi_carry(t_arg *arg, t_process *process)
{
	if (arg->error && process->reg[arg->vle[2] - 1] == 0
			&& process->carry == 0)
		process->carry = 1;
	else if (arg->error &&
					process->reg[arg->vle[2] - 1] != 0 && process->carry == 1)
		process->carry = 0;
}

void		op_lldi(t_virtual_machine *vm, t_process *process)
{
	t_arg	*arg;
	int		vle;
	int		argu[3];

	vle = 0;
	argu[0] = 0;
	argu[1] = 0;
	argu[2] = process->pc;
	arg = ft_fill_args(vm, process);
	if (arg->vle[2] > 0 && arg->vle[2] <= REG_NUMBER && arg->error)
	{
		argu[0] = (arg->type[0] == DIR_CODE) ?
		(short)arg->vle[0] : (short)arg->true_vle[0];
		if (arg->type[0] == REG_CODE)
			argu[0] = REV_MEM(process->reg[arg->vle[0] - 1], REG_SIZE);
		argu[1] = (arg->type[1] == REG_CODE) ?
		ft_reverse_memory_int(process->reg[arg->vle[1] - 1], REG_SIZE) :
		(short)arg->vle[1];
		argu[2] = process->pc + argu[0] + argu[1];
		argu[2] = ft_fix_neg_adrr(argu[2] % MEM_SIZE);
		vle = ft_read_cbc(vm, argu[2], REG_SIZE);
		process->reg[arg->vle[2] - 1] = vle;
	}
	op_lldi_carry(arg, process);
	op_lldi_finish(vm, process, arg, argu);
}
