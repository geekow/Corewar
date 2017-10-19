/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 03:28:12 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/06 01:25:02 by drimo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			main(int ac, char **av)
{
	t_virtual_machine vm;

	if (init_virtual_machine(&vm) == -1)
		write_error("Initiation of vm memory failled");
	parse_params(ac, av, &vm, 0);
	load_players(&vm);
	load_battlefield(&vm);
	if (vm.flags & FLAG_VISUALIZER)
		init_visualizer();
	if (vm.flags & FLAG_AUDIO)
		ft_audio_welcome();
	run_virtual_machine(&vm);
	free_lst(vm.processes);
	return (0);
}
