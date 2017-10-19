/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 20:16:15 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/03 02:18:00 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_in_mem_for_st(t_virtual_machine *vm, t_arg *arg, int adr,
								t_process *process)
{
	int	x;

	x = -1;
	while (++x < REG_SIZE)
		ft_memcpy(&vm->battlefield[(adr + x * sizeof(char)) % MEM_SIZE],
					((void*)arg->true_vle + x), sizeof(char));
	x = -1;
	while (++x < REG_SIZE)
		vm->colorsid[((adr % MEM_SIZE) % MEM_SIZE + x) % MEM_SIZE] =
					REV_MEM(process->fatherid, 4);
	x = -1;
	while (++x < REG_SIZE)
		vm->colors[((adr % MEM_SIZE) % MEM_SIZE + x) % MEM_SIZE] = 1;
}

void	op_st(t_virtual_machine *vm, t_process *process)
{
	t_arg		*arg;
	int			adr;

	adr = 0;
	arg = ft_fill_args(vm, process);
	if (arg->vle[0] > 0 && arg->vle[0] <= REG_NUMBER && arg->error)
	{
		if (arg->type[1] == REG_CODE && arg->vle[1] > 0
			&& arg->vle[1] <= REG_NUMBER)
			process->reg[arg->vle[1] - 1] = arg->true_vle[0];
		else if (arg->type[1] == IND_CODE)
		{
			adr = ft_fix_neg_adrr((process->pc + ((short)arg->vle[1] %
							IDX_MOD) % MEM_SIZE));
			write_in_mem_for_st(vm, arg, adr, process);
		}
	}
	process->pc += g_op_tab[(int)process->op].octal +
	ft_convert_intptr(arg->size, g_op_tab[(int)process->op].ac) + 1;
	process->pc = process->pc % MEM_SIZE;
	if (vm->flags & FLAG_VERBOSE && vm->flag_verbose_value & 4 &&
	(!(vm->flags & FLAG_VISUALIZER)) && arg->error)
		ft_printf("P %4i | %s r%d %d\n", process->id,
		g_op_tab[(int)process->op].name, arg->vle[0], arg->vle[1]);
	ft_free_args(arg);
}
