/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 19:44:08 by jjacobi           #+#    #+#             */
/*   Updated: 2017/09/30 22:33:04 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <form.h>

void	init_visualizer(void)
{
	initscr();
	clear();
	noecho();
	cbreak();
	start_color();
	curs_set(0);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_WHITE);
	init_pair(5 * 16, COLOR_BLACK, COLOR_RED);
	init_pair(2 * 16, COLOR_BLACK, COLOR_BLUE);
	init_pair(6 * 16, COLOR_BLACK, COLOR_CYAN);
	init_pair(4 * 16, COLOR_BLACK, COLOR_GREEN);
	init_pair(1 * 16, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(3 * 16, COLOR_BLACK, COLOR_YELLOW);
	refresh();
}

int		get_color(int i, t_virtual_machine *vm, int x, int is_space)
{
	t_list		*list;
	t_process	*process;

	if (x == 8)
		return (7);
	list = vm->processes;
	while (list && !is_space)
	{
		process = list->content;
		if (process->pc == i)
			return (is_player_id(vm, REV_MEM(process->fatherid, 4)) * 16);
		list = list->next;
	}
	if (vm->colors[i])
		return (is_player_id(vm, vm->colorsid[i]));
	return (7);
}

void	visu_battlefield(t_virtual_machine *vm)
{
	int i;
	int	linenb;
	int	x;

	i = -1;
	linenb = 0;
	x = 0;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
		{
			x = 0;
			linenb++;
		}
		if (i % 64 == 0 && i != (MEM_SIZE - 1) && (x += 8))
			mvprintw(linenb, x - 8, "0x%.4x :", i);
		attron(COLOR_PAIR(get_color(i, vm, x, 1)));
		mvprintw(linenb, x++, " ");
		attron(COLOR_PAIR(get_color(i, vm, x, 0)));
		mvprintw(linenb, x, "%.2hhx", vm->battlefield[i]);
		attron(COLOR_PAIR(7));
		x += 2;
	}
}

void	visu_info(t_virtual_machine *vm)
{
	int			i;

	mvprintw(1, 210, "   Turn counter: %5i", vm->turn_counter);
	mvprintw(2, 210, "    Current ctd: %5i", vm->ctd);
	mvprintw(3, 210, " Turns in cycle: %5i", vm->ctd_counter);
	mvprintw(5, 210, " Lives in cycle: %5i", vm->lives_in_cycle);
	mvprintw(8, 210, "Players list:");
	i = -1;
	while (++i < vm->nb_player)
	{
		mvprintw(10 + i, 210, "Id: ");
		attron(COLOR_PAIR(is_player_id(vm, vm->players[i].id)));
		mvprintw(10 + i, 214, "%4i", vm->players[i].id);
		attron(COLOR_PAIR(7));
		mvprintw(10 + i, 218, " Name: %15.15s Last live: %i",
					vm->players[i].name, vm->players[i].last_live_cycle);
	}
}

void	visualizer(t_virtual_machine *vm)
{
	int			i;
	t_list		*list;
	t_process	*process;

	visu_battlefield(vm);
	visu_info(vm);
	mvprintw(15, 210, "Processes list:");
	i = 16;
	list = vm->processes;
	while (list)
	{
		if (i++ < 63)
		{
			process = list->content;
			attron(COLOR_PAIR(is_player_id(vm,
			REV_MEM(process->fatherid, 4))));
			mvprintw(i, 210, "Pc: %4i", process->pc);
			attron(COLOR_PAIR(7));
			mvprintw(i, 219, "   Turns to wait: %4i Lives: %2i",
								process->op_wait, process->live_counter);
		}
		list = list->next;
	}
	nb_process_and_clear(i);
	refresh();
}
