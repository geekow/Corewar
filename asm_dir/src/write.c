/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:00:44 by jjaouen           #+#    #+#             */
/*   Updated: 2017/07/25 23:13:13 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void				ft_write_dir(t_asm *info, t_parse *nav, char *str)
{
	int				size;
	int				i;
	unsigned int	wd;
	static int		dir_size[16] = {4, 4, 0, 0, 0, 4, 4, 4, 2,
		2, 2, 2, 4, 2, 2, 4};

	i = 0;
	while (ft_strcmp(g_op_tab[i].name, nav->instruct) != 0)
		i++;
	size = dir_size[i];
	if (str[1] != LABEL_CHAR)
		wd = (unsigned int)ft_atoi_long(str + 1);
	else
		wd = (unsigned int)ft_get_vle_label(str + 2, nav->line, info);
	wd = (unsigned int)ft_reverse_memory_int((int)wd, size);
	write(info->fd_c, &wd, size);
}

void				ft_write_ind(t_asm *info, t_parse *nav, char *str)
{
	int				wd;

	wd = 0;
	if (str[0] != LABEL_CHAR)
		wd = (int)ft_atoi_long(str);
	else
		wd = ft_get_vle_label(str + 1, nav->line, info);
	wd = ft_reverse_memory_int(wd, 2);
	write(info->fd_c, &wd, 2);
}

void				write_file(t_asm *info)
{
	t_parse			*nav;
	int				index;

	nav = info->file;
	ft_write_header(info);
	while (nav)
	{
		index = 0;
		if (nav->label != NULL && nav->instruct == NULL)
			index = (int)index;
		else
		{
			while (ft_strcmp(nav->instruct, g_op_tab[index].name))
				index++;
			write(info->fd_c, &g_op_tab[index].op_code, 1);
			if (g_op_tab[index].octal_code)
				ft_write_ocp(info, nav);
			ft_write_param(info, nav);
		}
		nav = nav->next;
	}
}

void				ft_write_param(t_asm *info, t_parse *nav)
{
	int				i;
	int				registre_size;

	i = 0;
	while (i < 3)
	{
		if (nav->type_param[i] == T_REG)
		{
			registre_size = ft_atoi(nav->param[i] + 1);
			write(info->fd_c, &registre_size, 1);
		}
		else if (nav->type_param[i] == IND_SIZE)
			ft_write_ind(info, nav, nav->param[i]);
		else if (nav->type_param[i] == DIR_SIZE)
			ft_write_dir(info, nav, nav->param[i]);
		i++;
	}
}

void				ft_write_header(t_asm *info)
{
	int				rev_prog;

	rev_prog = ft_reverse_memory_int(info->header->prog_size, 4);
	info->header->prog_size = (unsigned int)rev_prog;
	info->fd_c = open(info->file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(info->fd_c, (void*)info->header, sizeof(t_header));
}
