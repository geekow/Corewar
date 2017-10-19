/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_live_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:34:01 by jjacobi           #+#    #+#             */
/*   Updated: 2017/09/11 21:57:53 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_last_live_player(t_virtual_machine *vm)
{
	int	i;
	int	last_live_cycle;
	int	result;

	result = 0;
	i = 0;
	last_live_cycle = -1;
	while (i < vm->nb_player)
	{
		if (last_live_cycle <= vm->players[i].last_live_cycle)
		{
			last_live_cycle = vm->players[i].last_live_cycle;
			result = i;
		}
		i++;
	}
	return (result);
}
