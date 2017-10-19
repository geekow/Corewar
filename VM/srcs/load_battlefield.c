/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_battlefield.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 03:38:20 by jjacobi           #+#    #+#             */
/*   Updated: 2017/09/30 21:47:22 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_champions(t_virtual_machine *vm)
{
	int		separator;
	int		start_add;
	int		i;
	int		x;

	i = -1;
	start_add = 0;
	separator = MEM_SIZE / vm->nb_player;
	while (++i < vm->nb_player)
	{
		ft_memcpy(&(vm->battlefield[start_add]), vm->players[i].code,
					vm->players[i].prog_size);
		x = -1;
		while (++x < vm->players[i].prog_size)
			vm->colorsid[(start_add + x) % MEM_SIZE] = vm->players[i].id;
		x = -1;
		while (++x < vm->players[i].prog_size)
			vm->colors[(start_add + x) % MEM_SIZE] = 1;
		vm->players[i].pc_address = start_add;
		start_add += separator;
	}
}

int		init_processes(t_virtual_machine *vm)
{
	t_process	process;
	t_list		*list;
	int			i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < vm->nb_player)
	{
		ft_memset(&process, 0, sizeof(t_process));
		process.id = ++vm->process_counter;
		process.pc = vm->players[i].pc_address;
		process.op = -1;
		process.fatherid = REV_MEM(vm->players[i].id, sizeof(int));
		process.reg[0] = REV_MEM(vm->players[i].id, sizeof(int));
		if (!(list = ft_lstnew(&process, sizeof(t_process))))
			return (-1);
		ft_lstadd(&(vm->processes), list);
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
i + 1, vm->players[i].prog_size, vm->players[i].name, vm->players[i].comment);
	}
	return (0);
}

void	free_lst(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free(list->content);
		free(list);
		list = next;
	}
}

void	load_battlefield(t_virtual_machine *vm)
{
	init_champions(vm);
	if (init_processes(vm) == -1)
	{
		free_lst(vm->processes);
		write_error("Memory allocation failed for process list");
	}
}
