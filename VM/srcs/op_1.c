/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:15:59 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/02 20:50:23 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <form.h>

void	op_live(t_virtual_machine *vm, t_process *process)
{
	int	id;
	int	i;

	process->live_counter++;
	process->last_live = vm->turn_counter;
	vm->lives_in_cycle++;
	id = ft_read_cbc(vm, (process->pc + 1) % MEM_SIZE, 4);
	id = ft_reverse_memory_int(id, 4);
	i = -1;
	if (vm->flags & FLAG_VERBOSE && vm->flag_verbose_value & 4 &&
	(!(vm->flags & FLAG_VISUALIZER)))
		ft_printf("P %4i | %s %d\n", process->id,
		g_op_tab[(int)process->op].name, id);
	while (++i < vm->nb_player)
	{
		if (vm->players[i].id == id)
		{
			if (!(vm->flags & FLAG_VISUALIZER) && vm->flag_verbose_value & 1)
				ft_printf("Player %i (%s) is said to be alive\n", i + 1,
					vm->players[i].name);
			vm->players[i].last_live_cycle = vm->turn_counter;
		}
	}
	process->pc += 5;
	process->pc %= MEM_SIZE;
}
