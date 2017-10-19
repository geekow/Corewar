/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drimo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:29:16 by drimo             #+#    #+#             */
/*   Updated: 2017/10/02 18:30:40 by drimo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void		ft_print_manage_error_header(char error, t_asm *info, char *line)
{
	if (error == -2)
		ft_dprintf(2, "%s%s:%s %sError:%s Multiple comment given\n",
				KWHT, info->original_name, KNRM, KRED, KNRM);
	else if (error == -3)
		ft_dprintf(2, "%s%s:%s %sError:%s %sLine %d:%s Missing double quote\n",
				KWHT, info->original_name, KNRM,
				KRED, KNRM, KGRN, g_ligne, KNRM);
	else if (error == -4)
		ft_dprintf(2, "%s%s:%s %sError:%s %sLine %d:%s Unknown expression: \
\"%s\"\n", KWHT, info->original_name, KNRM, KRED, KNRM, KGRN,
		g_ligne, KNRM, line);
}

void		ft_print_manage_error_header_2(char error, t_asm *info)
{
	if (error == -6)
		ft_dprintf(2,
				"%s%s:%s %sError:%s Name is too long. Maximum size is 128\n",
				KWHT, info->original_name, KNRM, KRED, KNRM);
	else if (error == -7)
		ft_dprintf(2,
	"%s%s:%s %sError:%s Comment is too long. Maximum size is 2048\n",
				KWHT, info->original_name, KNRM, KRED, KNRM);
}
