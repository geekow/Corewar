/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_15.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:17:03 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/02 19:35:49 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lfork(t_virtual_machine *vm, t_process *process)
{
	short		param;
	t_process	new_proc;

	param = ft_read_cbc(vm, (process->pc + 1) % MEM_SIZE, 2);
	param = ft_reverse_memory_int(param, 2);
	ft_memcpy(&new_proc, process, sizeof(t_process));
	new_proc.id = ++vm->process_counter;
	new_proc.op = -1;
	new_proc.op_wait = 0;
	new_proc.pc = ft_fix_neg_adrr((process->pc + param) % MEM_SIZE);
	if (vm->flags & FLAG_VERBOSE && vm->flag_verbose_value & 4 &&
		(!(vm->flags & FLAG_VISUALIZER)))
		ft_printf("P %4i | lfork %i (%i)\n", process->id, param, new_proc.pc);
	new_proc.pc %= MEM_SIZE;
	ft_lstadd(&(vm->processes), ft_lstnew(&new_proc, sizeof(t_process)));
	process->pc += 3;
	process->pc %= MEM_SIZE;
}
