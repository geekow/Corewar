/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:05:31 by jjaouen           #+#    #+#             */
/*   Updated: 2017/07/25 23:07:15 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int			ft_write_ocp(t_asm *info, t_parse *line)
{
	int		i;
	int		vle;

	i = -1;
	vle = 0;
	while (++i < 3)
	{
		if (line->type_param[i] == T_REG)
			vle = (vle << 2) + REG_CODE;
		else if (line->type_param[i] == IND_SIZE)
			vle = (vle << 2) + IND_CODE;
		else if (line->type_param[i] == DIR_SIZE)
			vle = (vle << 2) + DIR_CODE;
	}
	vle = (vle <= 3 ? (vle << 2) : vle);
	vle = (vle <= 15 ? (vle << 2) : vle);
	vle = (vle << 2);
	write(info->fd_c, &vle, 1);
	return (vle);
}
