/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 22:36:32 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/06 02:58:09 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "os.h"

void	get_param(char **av, int *i, t_virtual_machine *vm, int ac)
{
	char	*ptr;

	if ((!ft_strcmp("-dump", av[*i]) || !ft_strcmp("-d", av[*i])) && (*i)++)
		reg_dump(ac - *i, av[*i], vm);
	else if ((!ft_strcmp("-v", av[*i])) && (*i)++)
		reg_verbose(ac - *i, av[*i], vm);
	else if (!ft_strcmp("-i", av[*i]))
		vm->flags |= FLAG_VISUALIZER;
	else if (!ft_strcmp("-s", av[*i]) && (*i)++)
		reg_sbs(ac - *i, av[*i], vm);
	else if (!ft_strcmp("-a", av[*i]))
		vm->flags |= FLAG_AFF;
	else if ((!ft_strcmp("-o", av[*i])) && OS)
		vm->flags |= FLAG_AUDIO;
	else if (!ft_strcmp("-n", av[*i]) && (*i)++ && (*i)++)
		reg_player_with_id(ac - *i, av + ((*i - 1) * sizeof(char)), vm);
	else if ((ptr = ft_strstr(av[*i], ".cor")) && ptr != av[*i] && !ptr[4])
		*i = *i + 1 - 1;
	else
		write_usage();
}

void	parse_params(int ac, char **av, t_virtual_machine *vm, int i)
{
	char	*ptr;

	while (++i < ac)
		get_param(av, &i, vm, ac);
	i = 0;
	while (++i < ac)
		if ((i < 3 || ft_strcmp("-n", av[i - 2])) &&
			(ptr = ft_strstr(av[i], ".cor")) && ptr != av[i] && !ptr[4])
			get_player_info(vm, av[i], NULL);
}
