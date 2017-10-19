/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_9.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:16:43 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/02 18:11:20 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjmp(t_virtual_machine *vm, t_process *process)
{
	t_arg	*arg;
	int		adrr;
	int		error;

	adrr = 0;
	error = 1;
	arg = ft_fill_args(vm, process);
	if (process->carry == 1)
	{
		adrr += (process->pc + (short)arg->vle[0] % IDX_MOD);
		process->pc = ft_fix_neg_adrr(adrr % MEM_SIZE);
		error = 0;
	}
	else
		process->pc += g_op_tab[(int)process->op].octal +
		ft_convert_intptr(arg->size, g_op_tab[(int)process->op].ac) + 1;
	process->pc = process->pc % MEM_SIZE;
	if (vm->flags & FLAG_VERBOSE && vm->flag_verbose_value & 4 &&
	(!(vm->flags & FLAG_VISUALIZER)))
		ft_printf("P %4i | %s %d %s\n", process->id,
		g_op_tab[(int)process->op].name, (short)arg->vle[0], error == 1 ?
		"FAILED" : "OK");
	ft_free_args(arg);
}
