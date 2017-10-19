/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_args_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drimo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:24:24 by drimo             #+#    #+#             */
/*   Updated: 2017/10/03 02:29:21 by drimo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					*ft_get_tabtype(t_virtual_machine *vm, t_process *process)
{
	int				opc;
	int				*type;
	int				ac;

	opc = ft_reverse_memory_int((int)vm->battlefield[(process->pc + 1) %
			MEM_SIZE], 1);
	ac = g_op_tab[(int)process->op].ac;
	type = ft_memalloc(sizeof(int) * ac);
	if (process->op + 1 == 9)
	{
		if (process->op + 1 == 9)
			type[0] = DIR_CODE;
		return (type);
	}
	if (ac > 0)
		type[0] = opc >> 6;
	if (ac > 1)
		type[1] = (opc >> 4) & 0x3;
	if (ac > 2)
		type[2] = (opc >> 2) & 0x3;
	return (type);
}

int					*ft_get_tabsize(int *type, t_process *process)
{
	int				*size;
	int				ac;
	int				dir_size;
	static int		dir_tab[16] = {4, 4, 4, 4, 4, 4, 4, 4, 2,
		2, 2, 2, 4, 2, 2, 4};
	int				i;

	i = 0;
	dir_size = dir_tab[(int)process->op];
	ac = g_op_tab[(int)process->op].ac;
	size = ft_memalloc(sizeof(int) * ac);
	while (i < ac)
	{
		if (type[i] == REG_CODE)
			size[i] = 1;
		else if (type[i] == IND_CODE || (type[i] == DIR_CODE && dir_size == 2))
			size[i] = 2;
		else if (type[i] == DIR_CODE && dir_size == 4)
			size[i] = 4;
		else
			size[i] = 0;
		i++;
	}
	return (size);
}

void				ft_check_error_arg(t_arg *arg, t_process *process)
{
	int				op;
	int				ac;
	int				i;

	i = -1;
	op = (int)process->op;
	ac = g_op_tab[op].ac;
	arg->error = 1;
	while (++i != ac)
	{
		if (arg->type[i] == IND_CODE)
		{
			if (T_IND != (g_op_tab[op].args[i] & T_IND))
				arg->error = 0;
		}
		else if (arg->type[i] == DIR_CODE || arg->type[i] == REG_CODE)
		{
			if ((arg->type[i] != (g_op_tab[op].args[i] &
			arg->type[i])) || (arg->type[i] == REG_CODE && (arg->vle[i] <= 0 ||
			arg->vle[i] > REG_NUMBER)))
				arg->error = 0;
		}
		else
			arg->error = 0;
	}
}

t_arg				*ft_fill_args(t_virtual_machine *vm, t_process *process)
{
	t_arg			*arg;

	arg = (t_arg*)ft_memalloc(sizeof(t_arg));
	arg->type = ft_get_tabtype(vm, process);
	arg->size = ft_get_tabsize(arg->type, process);
	ft_get_tabvle(vm, process, arg);
	ft_check_error_arg(arg, process);
	return (arg);
}
