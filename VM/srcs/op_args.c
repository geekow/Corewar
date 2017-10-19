/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 01:48:41 by jjaouen           #+#    #+#             */
/*   Updated: 2017/10/03 02:25:30 by drimo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			ft_free_args(t_arg *arg)
{
	ft_memdel((void**)&arg->type);
	ft_memdel((void**)&arg->size);
	ft_memdel((void**)&arg->vle);
	ft_memdel((void**)&arg->true_vle);
	ft_memdel((void**)&arg);
}

int				ft_read_cbc(t_virtual_machine *vm, int pc, int size)
{
	int			vle;
	int			x;

	vle = 0;
	x = -1;
	while (++x < size)
		ft_memcpy((void*)&vle + x, (void*)&vm->battlefield[(pc + x) %
					MEM_SIZE], 1);
	return (vle);
}

void			ft_parse_reg(t_virtual_machine *vm, t_process *process,
		t_arg *arg, int i)
{
	arg->vle[i] = vm->battlefield[(process->pc +
	g_op_tab[(int)process->op].octal +
	ft_convert_intptr(arg->size, i + 1)) % MEM_SIZE];
	(arg->vle[i] > 0 && arg->vle[i] <= REG_NUMBER) ?
	(arg->true_vle[i] = process->reg[arg->vle[i] - 1]) :
	(arg->true_vle[i] = 0);
}

void			ft_parse_dir_and_ind(t_virtual_machine *vm, t_process *process,
		t_arg *arg, int i)
{
	int		adr;

	adr = 0;
	arg->vle[i] = ft_read_cbc(vm, (process->pc
	+ g_op_tab[(int)process->op].octal + ft_convert_intptr(arg->size, i)
	+ 1) % MEM_SIZE, arg->size[i]);
	arg->vle[i] = ft_reverse_memory_int(arg->vle[i], arg->size[i]);
	if (arg->type[i] == IND_CODE)
	{
		arg->vle[i] = (short)arg->vle[i];
		if ((int)process->op + 1 == 13 ||
		(int)process->op + 1 == 14)
		{
			adr = ft_fix_neg_adrr((process->pc + arg->vle[i]) % MEM_SIZE);
			arg->true_vle[i] = ft_read_cbc(vm, adr, REG_SIZE);
		}
		else
		{
			adr = ft_fix_neg_adrr(process->pc +
			(arg->vle[i] % IDX_MOD) % MEM_SIZE);
			arg->true_vle[i] = ft_read_cbc(vm, adr, REG_SIZE);
		}
	}
	else if (arg->type[i] == DIR_CODE)
		arg->true_vle[i] = REV_MEM(arg->vle[i], arg->size[i]);
}

void			ft_get_tabvle(t_virtual_machine *vm, t_process *process,
		t_arg *arg)
{
	int		ac;
	int		i;

	i = -1;
	ac = g_op_tab[(int)process->op].ac;
	arg->vle = ft_memalloc(sizeof(int) * ac);
	arg->true_vle = ft_memalloc(sizeof(int) * ac);
	while (++i < ac)
	{
		if (arg->type[i] == REG_CODE)
			ft_parse_reg(vm, process, arg, i);
		else if (arg->type[i] == IND_CODE || arg->type[i] == DIR_CODE)
			ft_parse_dir_and_ind(vm, process, arg, i);
	}
}
