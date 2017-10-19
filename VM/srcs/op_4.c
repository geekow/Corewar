/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:16:19 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/03 02:05:17 by drimo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	ft_condition_add(t_arg *arg)
{
	if (arg->vle[0] > 0 && arg->vle[0] <= REG_NUMBER && arg->vle[1] > 0 &&
	arg->vle[1] <= REG_NUMBER && arg->vle[2] > 0 &&
	arg->vle[2] <= REG_NUMBER && arg->error)
		return (1);
	else
		return (0);
}

void	ft_print_addv(t_process *process, t_arg *arg)
{
	ft_printf("P %4i | %s r%d r%d r%d\n", process->id,
		g_op_tab[(int)process->op].name, arg->vle[0], arg->vle[1],
		arg->vle[2]);
}

void	op_add(t_virtual_machine *vm, t_process *process)
{
	t_arg	*arg;
	int		error;

	error = 0;
	arg = ft_fill_args(vm, process);
	if (ft_condition_add(arg))
		process->reg[arg->vle[2] - 1] =
		ft_reverse_memory_int(ft_reverse_memory_int(arg->true_vle[0],
		REG_SIZE) + ft_reverse_memory_int(arg->true_vle[1],
		REG_SIZE), REG_SIZE);
	else
		error = 1;
	process->pc += g_op_tab[(int)process->op].octal +
	ft_convert_intptr(arg->size, g_op_tab[(int)process->op].ac) + 1;
	if (arg->error && error == 0 && process->reg[arg->vle[2] - 1] == 0 &&
	process->carry == 0)
		process->carry = 1;
	else if (arg->error && error == 0 && process->reg[arg->vle[2] - 1]
	!= 0 && process->carry == 1)
		process->carry = 0;
	if (vm->flags & FLAG_VERBOSE && vm->flag_verbose_value & 4 &&
	(!(vm->flags & FLAG_VISUALIZER)) && arg->error)
		ft_print_addv(process, arg);
	process->pc = process->pc % MEM_SIZE;
	ft_free_args(arg);
}
