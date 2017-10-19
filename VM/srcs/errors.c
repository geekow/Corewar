/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 21:23:49 by jjacobi           #+#    #+#             */
/*   Updated: 2017/10/06 02:47:36 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_error(char *str)
{
	ft_dprintf(STDERR_FILENO, str);
	ft_dprintf(STDERR_FILENO, "\n");
	exit(-1);
}

void	write_usage(void)
{
	ft_dprintf(STDERR_FILENO, "usage: corewar [-a | -dump N | -v N | \
-i | -s] <[-n N] champion.cor> <...>\n");
	ft_dprintf(STDERR_FILENO, "\t-n N : Specify the player ID\n");
	ft_dprintf(STDERR_FILENO, "\t-a : Display Aff OP\n");
	ft_dprintf(STDERR_FILENO, "\t-d N : Dump memory at cycle N\n");
	ft_dprintf(STDERR_FILENO, "\t-v N : Mode verbose N >= 0 && N <= 15");
	ft_dprintf(STDERR_FILENO, "\n\t\t- 0 : Show only essentials");
	ft_dprintf(STDERR_FILENO, "\n\t\t- 1 : Show lives");
	ft_dprintf(STDERR_FILENO, "\n\t\t- 2 : Show cycles");
	ft_dprintf(STDERR_FILENO, "\n\t\t- 4 : Show operations");
	ft_dprintf(STDERR_FILENO, "\n\t\t- 8 : Show deaths\n");
	ft_dprintf(STDERR_FILENO, "\t-s N : Mode step by step from the cycle N: \
Use Space or Enter\n");
	ft_dprintf(STDERR_FILENO, "\t-i : Ncurses output\n");
	ft_dprintf(STDERR_FILENO, "\t\t- Use p/P for sleep\n");
	ft_dprintf(STDERR_FILENO, "\t-o : Mode audio (MAC_OS only)\n");
	exit(0);
}
