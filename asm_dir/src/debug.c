/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 20:44:26 by jjaouen           #+#    #+#             */
/*   Updated: 2017/07/25 22:51:39 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void		ft_print_parser(t_asm *info)
{
	t_parse *nav;

	nav = info->file;
	while (nav)
	{
		ft_printf("line = %d\nlabel = %s\ninstruct = %s\n", nav->line,
			nav->label, nav->instruct);
		ft_print_words_tables(nav->param);
		ft_printf("TYPE PARAM : [%d] [%d] [%d]\n",
				nav->type_param[0], nav->type_param[1], nav->type_param[2]);
		ft_printf("\n");
		nav = nav->next;
	}
}
