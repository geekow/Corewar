/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 02:46:20 by jjaouen           #+#    #+#             */
/*   Updated: 2017/10/06 02:46:23 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "form.h"

void		ft_event_pause(void)
{
	int	k;

	nodelay(stdscr, 1);
	k = getch();
	if (k == 112 || k == 80)
	{
		k = -1;
		while (k != 112 && k != 80)
			k = getch();
	}
	nodelay(stdscr, 0);
}

void		ft_event_sbs(t_virtual_machine *vm)
{
	int	k;

	k = -1;
	while (k != 10)
	{
		if (vm->flags & FLAG_VISUALIZER && k == 32)
			break ;
		if (!(vm->flags & FLAG_VISUALIZER))
			k = getchar();
		else
			k = getch();
	}
}
