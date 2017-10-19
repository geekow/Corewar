/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_virtual_machine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 09:16:25 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/06 02:46:33 by drimo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <form.h>

void	killproc(t_virtual_machine *vm, t_process *process)
{
	if (vm->flags & FLAG_VERBOSE && vm->flag_verbose_value & 8)
	{
		if (!(vm->flags & FLAG_VISUALIZER))
			ft_printf("Process %i hasn't lived for %i cycles (CTD %i)\n",
			process->id, vm->turn_counter - process->last_live,
			vm->ctd_counter);
	}
	if (vm->flags & FLAG_AUDIO)
		ft_audio_kill_process(vm);
	free(process);
}

void	remove_dead_processes(t_virtual_machine *vm)
{
	t_list		*list;
	t_list		*tmp;
	t_list		*previous;
	t_process	*process;

	previous = NULL;
	list = vm->processes;
	while (list)
		if ((process = list->content) && (process->live_counter == 0
				|| vm->ctd < 0))
		{
			killproc(vm, process);
			if (previous)
				previous->next = list->next;
			else
				vm->processes = list->next;
			tmp = list;
			list = list->next;
			free(tmp);
		}
		else if (!(process->live_counter = 0))
		{
			previous = list;
			list = list->next;
		}
}

void	update_vm_env(t_virtual_machine *vm)
{
	if (vm->ctd_counter == vm->ctd)
	{
		if (vm->lives_in_cycle >= NBR_LIVE)
		{
			vm->ctd -= CYCLE_DELTA;
			vm->check_counter = -1;
			if (vm->flags & FLAG_VERBOSE && vm->flag_verbose_value & 2 &&
					!(vm->flags & FLAG_VISUALIZER))
				ft_printf("Cycle to die is now %i\n", vm->ctd);
		}
		vm->check_counter++;
		if (vm->check_counter == MAX_CHECKS)
		{
			vm->ctd--;
			vm->check_counter = 0;
		}
		vm->ctd_counter = 0;
		vm->lives_in_cycle = 0;
	}
	vm->turn_counter++;
	if (!(vm->flags & FLAG_VISUALIZER) && vm->flags & FLAG_VERBOSE
			&& vm->flag_verbose_value & 2)
		ft_printf("It is now cycle %i\n", vm->turn_counter);
	vm->ctd_counter++;
}

void	play_turn(t_virtual_machine *vm)
{
	t_list		*list;
	t_process	*process;

	list = vm->processes;
	while (list)
	{
		process = list->content;
		if (process->op < 0 || process->op > 15)
			get_next_op(vm, process);
		if (process->op_wait == 0 && process->op >= 0 && process->op <= 15)
		{
			g_op_tab[(unsigned)process->op].f(vm, process);
			process->op = -1;
		}
		else if (process->op_wait)
			process->op_wait--;
		list = list->next;
	}
}

void	run_virtual_machine(t_virtual_machine *vm)
{
	while (vm->processes != NULL)
	{
		if (vm->turn_counter == vm->flag_dump_value)
		{
			if (vm->flags & FLAG_VISUALIZER)
				endwin();
			dump_battlefield(vm);
			break ;
		}
		if (vm->ctd_counter == vm->ctd || vm->ctd < 0)
			remove_dead_processes(vm);
		update_vm_env(vm);
		play_turn(vm);
		if (vm->flags & FLAG_VISUALIZER && vm->turn_counter % TURBO == 0)
			visualizer(vm);
		if (vm->flags & FLAG_STEPBYSTEP && vm->turn_counter >= VLE_SBS)
			ft_event_sbs(vm);
		if (vm->flags & FLAG_VISUALIZER)
			ft_event_pause();
	}
	if (vm->flags & FLAG_VISUALIZER)
		endwin();
	if (vm->turn_counter != vm->flag_dump_value && ft_audio_close(vm))
		ft_printf("Contestant %d, \"%s\", has won !\n",
	get_last_live_player(vm) + 1, vm->players[get_last_live_player(vm)].name);
}
