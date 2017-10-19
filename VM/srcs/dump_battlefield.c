/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_battlefield.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 17:48:09 by jjacobi           #+#    #+#             */
/*   Updated: 2017/08/13 17:48:22 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_battlefield(t_virtual_machine *vm)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
			ft_printf(" \n");
		if (i % 64 == 0 && i != (MEM_SIZE - 1))
			ft_printf("0x%.4x :", i);
		ft_printf(" %.2hhx", vm->battlefield[i]);
	}
	ft_printf(" \n");
}
