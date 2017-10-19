/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_virtual_machine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 21:15:47 by jjacobi           #+#    #+#             */
/*   Updated: 2017/08/13 19:13:44 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		init_virtual_machine(t_virtual_machine *vm)
{
	ft_memset(vm, 0, sizeof(t_virtual_machine));
	vm->flag_dump_value = -1;
	vm->ctd = CYCLE_TO_DIE;
	return (0);
}
