/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 16:44:34 by jjacobi           #+#    #+#             */
/*   Updated: 2017/08/15 15:26:20 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_next_op(t_virtual_machine *vm, t_process *process)
{
	if (vm->battlefield[process->pc] > 16 || vm->battlefield[process->pc] < 1)
	{
		process->op = -1;
		process->pc++;
		process->pc %= MEM_SIZE;
	}
	else
	{
		process->op = vm->battlefield[process->pc] - 1;
		process->op_wait = g_op_tab[(unsigned)process->op].cycle - 1;
	}
}
