/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_16.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:17:06 by jjacobi           #+#    #+#             */
/*   Updated: 2017/09/30 22:14:15 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_virtual_machine *vm, t_process *process)
{
	char	content_reg;
	t_arg	*arg;

	arg = ft_fill_args(vm, process);
	content_reg = 0;
	if (arg->vle[0] > 0 && arg->vle[0] <= REG_NUMBER && arg->error)
	{
		content_reg = (char)(REV_MEM(arg->true_vle[0], 4) % 256);
		if (!(vm->flags & FLAG_VISUALIZER) && (vm->flags & FLAG_AFF))
			ft_printf("Aff: %c\n", content_reg);
	}
	process->pc += g_op_tab[(int)process->op].octal +
	ft_convert_intptr(arg->size, g_op_tab[(int)process->op].ac) + 1;
	process->pc = process->pc % MEM_SIZE;
	ft_free_args(arg);
}
