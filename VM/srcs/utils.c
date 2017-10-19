/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:08:54 by jjacobi           #+#    #+#             */
/*   Updated: 2017/09/30 22:32:19 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <form.h>

int	ft_fix_neg_adrr(int pos)
{
	int		v;

	v = 0;
	if (pos < 0)
	{
		v = (pos / (-MEM_SIZE)) + 1;
		pos = pos + v * (MEM_SIZE);
	}
	return (pos % MEM_SIZE);
}

int	ft_reverse_memory_int(int vle, int size)
{
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	size = ((size - 1) * 8);
	while (i <= size)
	{
		ret |= ((vle >> (size - i) & 0xff)) << i;
		i += 8;
	}
	return (ret);
}

int	ft_convert_intptr(int *size, int len)
{
	int		result;
	int		i;

	result = 0;
	i = -1;
	while (++i < len)
		result += size[i];
	return (result);
}

int	is_player_id(t_virtual_machine *vm, int id)
{
	int i;

	i = 0;
	while (i < vm->nb_player)
	{
		if (vm->players[i].id == id)
			return (abs(id) % 6 + 1);
		i++;
	}
	return (8);
}

int	nb_process_and_clear(int i)
{
	mvprintw(6, 208, "Processes counter: %5i", i - 12);
	while (i < 63)
		mvprintw(++i, 210, "                                         ");
	return (0);
}
