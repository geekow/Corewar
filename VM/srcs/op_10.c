/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_10.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:16:46 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/03 02:52:03 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_ldi_next(t_virtual_machine *vm, t_process *process, int *argtab,
		t_arg *arg)
{
	int		vle;
	int		adrr;

	vle = 0;
	adrr = 0;
	adrr = process->pc + ((argtab[0] + argtab[1]) % IDX_MOD);
	if (vm->flags & FLAG_VERBOSE && vm->flag_verbose_value & 4 &&
	(!(vm->flags & FLAG_VISUALIZER)) && arg->error)
	{
		ft_printf("P %4i | %s %d %d r%d\n%7s| -> load from %d + %d = %d ",
		process->id, g_op_tab[(int)process->op].name, argtab[0], argtab[1],
		arg->vle[2], "", argtab[0], argtab[1], (argtab[0] + argtab[1]));
		ft_printf("(with pc and mod %d)\n", adrr);
	}
	adrr = ft_fix_neg_adrr(adrr % MEM_SIZE);
	vle = ft_read_cbc(vm, adrr, REG_SIZE);
	REG[arg->vle[2] - 1] = vle;
}

void		op_ldi(t_virtual_machine *vm, t_process *process)
{
	t_arg	*arg;
	int		argtab[2];

	argtab[0] = 0;
	argtab[1] = 0;
	arg = ft_fill_args(vm, process);
	if (arg->vle[2] > 0 && arg->vle[2] <= REG_NUMBER && arg->error)
	{
		argtab[0] = (arg->type[0] == DIR_CODE) ?
		(short)arg->vle[0] : (short)arg->true_vle[0];
		if (arg->type[0] == REG_CODE)
			argtab[0] = REV_MEM(REG[arg->vle[0] - 1], REG_SIZE);
		argtab[1] = (arg->type[1] == REG_CODE) ?
		REV_MEM(REG[arg->vle[1] - 1], REG_SIZE) : (short)arg->vle[1];
		ft_ldi_next(vm, process, argtab, arg);
	}
	process->pc += g_op_tab[(int)process->op].octal +
	ft_convert_intptr(arg->size, g_op_tab[(int)process->op].ac) + 1;
	process->pc = process->pc % MEM_SIZE;
	ft_free_args(arg);
}
