/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 02:37:52 by jjacobi           #+#    #+#             */
/*   Updated: 2017/08/10 13:04:01 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_id(t_virtual_machine *vm, int *idptr)
{
	int i;
	int id;

	id = -1;
	if (idptr)
		id = *idptr;
	i = 0;
	while (i < vm->nb_player)
	{
		if (vm->players[i].id == id && idptr)
			write_error("Error: Duplicated champion id");
		else if (vm->players[i].id == id)
		{
			id--;
			i = -1;
		}
		i++;
	}
	return (id);
}

void	get_player_info(t_virtual_machine *vm, char *path, int *idptr)
{
	if (vm->nb_player >= MAX_PLAYERS)
		write_error("Too many champions");
	vm->players[vm->nb_player].id = get_id(vm, idptr);
	vm->players[vm->nb_player].path = path;
	vm->nb_player++;
}
