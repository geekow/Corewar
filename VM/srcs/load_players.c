/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 00:05:03 by jjacobi           #+#    #+#             */
/*   Updated: 2017/08/30 08:43:55 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>

void	check_exec_magic(int i)
{
	unsigned char	nb[4];

	nb[0] = (char)((i & 0xFF000000) >> 24);
	nb[1] = (char)((i & 0x00FF0000) >> 16);
	nb[2] = (char)((i & 0x0000FF00) >> 8);
	nb[3] = (char)(i & 0x000000FF);
	if (*(unsigned int *)nb != COREWAR_EXEC_MAGIC)
		write_error("Wrong exec_magic number");
}

void	read_player(t_player *player)
{
	int	fd;

	if ((fd = open(player->path, O_RDONLY)) != -1)
	{
		read(fd, &(player->exec_magic), sizeof(int));
		check_exec_magic(player->exec_magic);
		read(fd, &(player->name), PROG_NAME_LENGTH);
		lseek(fd, 8, SEEK_CUR);
		read(fd, &(player->comment), COMMENT_LENGTH);
		lseek(fd, 4, SEEK_CUR);
		player->prog_size = read(fd, &(player->code), CHAMP_MAX_SIZE + 1);
		if (player->prog_size > CHAMP_MAX_SIZE)
			write_error("The champion is bigger then CHAMP_MAX_SIZE");
	}
	else
		write_error("Unable to open champion file");
	close(fd);
}

void	load_players(t_virtual_machine *vm)
{
	int	i;

	i = -1;
	if (vm->nb_player < 1)
		write_usage();
	while (++i < vm->nb_player)
	{
		read_player(&vm->players[i]);
	}
}
