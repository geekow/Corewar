/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_11.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:16:49 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/03 02:38:55 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	mem_write_for_sti(t_virtual_machine *vm, t_arg *arg, int adrr,
															t_process *process)
{
	int	x;

	x = -1;
	while (++x < REG_SIZE)
		ft_memcpy(&vm->battlefield[(adrr + x * sizeof(char)) %
		MEM_SIZE], (char*)arg->true_vle + x, sizeof(char));
	x = -1;
	while (++x < REG_SIZE)
		vm->colorsid[(adrr + x) % MEM_SIZE] = REV_MEM(process->fatherid, 4);
	x = -1;
	while (++x < REG_SIZE)
		vm->colors[(adrr + x) % MEM_SIZE] = 1;
}

void	verbose_msg_sti(t_virtual_machine *vm, t_arg *arg, int argt[2],
		t_process *process)
{
	if (vm->flags & FLAG_VERBOSE && vm->flag_verbose_value & 4 &&
	(!(vm->flags & FLAG_VISUALIZER)) && arg->error)
	{
		ft_printf("P %4i | %s r%d %d %d\n%7s| -> store to %d + %d = %d ",
		process->id, g_op_tab[(int)process->op].name, arg->vle[0],
		argt[0], argt[1], "", argt[0], argt[1], (argt[0] + argt[1]));
		ft_printf("(with pc and mod %d)\n",
			process->pc + ((argt[0] + argt[1]) % IDX_MOD) % MEM_SIZE);
	}
}

void	op_sti(t_virtual_machine *vm, t_process *process)
{
	t_arg		*arg;
	int			adrr;
	int			argt[2];

	adrr = process->pc;
	argt[0] = 0;
	argt[1] = 0;
	arg = ft_fill_args(vm, process);
	if (arg->vle[0] > 0 && arg->vle[0] <= REG_NUMBER && arg->error)
	{
		argt[0] = (arg->type[1] == DIR_CODE) ?
		(short)arg->vle[1] : (short)arg->true_vle[1];
		if (arg->type[1] == REG_CODE)
			argt[0] = REV_MEM(process->reg[arg->vle[1] - 1], REG_SIZE);
		argt[1] = (arg->type[2] == REG_CODE) ?
		REV_MEM(process->reg[arg->vle[2] - 1], REG_SIZE) : (short)arg->vle[2];
		adrr += ((argt[0] + argt[1]) % IDX_MOD) % MEM_SIZE;
		adrr = ft_fix_neg_adrr(adrr);
		mem_write_for_sti(vm, arg, adrr, process);
	}
	verbose_msg_sti(vm, arg, argt, process);
	process->pc += g_op_tab[(int)process->op].octal +
	ft_convert_intptr(arg->size, g_op_tab[(int)process->op].ac) + 1;
	process->pc = process->pc % MEM_SIZE;
	ft_free_args(arg);
}
