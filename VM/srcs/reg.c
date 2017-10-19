/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 03:56:11 by jjaouen           #+#    #+#             */
/*   Updated: 2017/10/07 03:56:16 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	reg_dump(int ac_verif, char *next_av, t_virtual_machine *vm)
{
	int	i;

	i = 0;
	if (ac_verif <= 0)
		write_usage();
	vm->flags |= FLAG_DUMP;
	while (next_av[i])
		if (!ft_isdigit(next_av[i++]))
			write_usage();
	vm->flag_dump_value = ft_atoi(next_av);
}

void	reg_verbose(int ac_verif, char *next_av, t_virtual_machine *vm)
{
	int	i;

	i = 0;
	if (ac_verif <= 0)
		write_usage();
	vm->flags |= FLAG_VERBOSE;
	while (next_av[i])
		if (!ft_isdigit(next_av[i++]))
			write_usage();
	vm->flag_verbose_value = ft_atoi(next_av);
	if (vm->flag_verbose_value >= 16)
		write_usage();
}

void	reg_player_with_id(int ac_verif, char **av, t_virtual_machine *vm)
{
	int		i;
	int		player_nbr;
	char	*ptr;

	i = 0;
	if (ac_verif <= 0)
		write_usage();
	while (av[0][i++])
		if (av[0][i - 1] != '-' && !ft_isdigit(av[0][i - 1]))
			write_usage();
	player_nbr = ft_atoi(av[0]);
	if ((ptr = ft_strstr(av[1], ".cor")) && ptr != av[1] && !ptr[4])
		get_player_info(vm, av[1], &player_nbr);
	else
		write_usage();
}

void	reg_sbs(int ac_verif, char *next_av, t_virtual_machine *vm)
{
	int	i;

	i = 0;
	if (ac_verif <= 0)
		write_usage();
	vm->flags |= FLAG_STEPBYSTEP;
	while (next_av[i])
		if (!ft_isdigit(next_av[i++]))
			write_usage();
	vm->flag_sbs_value = ft_atoi(next_av);
	if (vm->flag_sbs_value < 1)
		write_usage();
}
