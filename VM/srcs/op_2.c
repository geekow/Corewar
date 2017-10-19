/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:16:11 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/02 18:07:42 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ld(t_virtual_machine *vm, t_process *process)
{
	t_arg	*arg;
	int		error;

	error = 0;
	arg = ft_fill_args(vm, process);
	if (arg->vle[1] > 0 && arg->vle[1] <= REG_NUMBER && arg->error)
		process->reg[arg->vle[1] - 1] = arg->true_vle[0];
	else
		error = 1;
	process->pc += g_op_tab[(int)process->op].octal +
	ft_convert_intptr(arg->size, g_op_tab[(int)process->op].ac) + 1;
	if (error == 0 && arg->error && process->reg[arg->vle[1] - 1] == 0
	&& process->carry == 0)
		process->carry = 1;
	else if (error == 0 && arg->error &&
	process->reg[arg->vle[1] - 1] != 0 && process->carry == 1)
		process->carry = 0;
	process->pc = process->pc % MEM_SIZE;
	if (vm->flags & FLAG_VERBOSE && !(vm->flags & FLAG_VISUALIZER) &&
									arg->error && vm->flag_verbose_value & 4)
		ft_printf("P %4i | %s %d r%d\n", process->id,
		g_op_tab[(int)process->op].name, REV_MEM(arg->true_vle[0],
		REG_SIZE), arg->vle[1]);
	ft_free_args(arg);
}
