/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drimo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 01:09:22 by drimo             #+#    #+#             */
/*   Updated: 2017/10/06 03:00:31 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			ft_audio_welcome(void)
{
	pid_t		father;

	father = fork();
	if (father == 0)
		execve("/usr/bin/say",
	ft_strsplit("say -v Samantha Welcome to the battlefield !", ' '), NULL);
}

int				ft_audio_close(t_virtual_machine *vm)
{
	pid_t		father;
	char		*line;

	if (vm->flags & FLAG_AUDIO)
	{
		father = fork();
		line = "say -v Samantha The battle is over ! The winner is ";
		if (father == 0)
		{
			line = ft_strjoin(line,
	(char *)vm->players[get_last_live_player(vm)].name);
			execve("/usr/bin/say",
	ft_strsplit(line, ' '), NULL);
		}
	}
	return (1);
}

void			ft_audio_kill_process(t_virtual_machine *vm)
{
	pid_t		father;
	static int	i = 0;

	if (i != vm->turn_counter)
	{
		i = vm->turn_counter;
		father = fork();
		if (father == 0)
			execve("/usr/bin/afplay",
	ft_strsplit("afplay audio/kill.mp3", ' '), NULL);
	}
}
