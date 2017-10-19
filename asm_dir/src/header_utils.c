/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:02:23 by jjaouen           #+#    #+#             */
/*   Updated: 2017/10/01 00:37:40 by Dov              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

char			ft_is_name(char *line, t_asm *info)
{
	char		error;

	error = 1;
	if (info->name_count != 0)
		return (-1);
	error = ft_copy_name(line, info);
	return (error);
}

char			ft_is_comment(char *line, t_asm *info)
{
	char		error;

	error = 1;
	if (info->comment_count != 0)
		return (-2);
	error = ft_copy_comment(line, info);
	return (error);
}

int				ft_get_size(t_parse *file)
{
	int			total;
	int			op_index;
	static int	dir_size[16] = {4, 4, 0, 0, 0, 4, 4, 4, 2,
		2, 2, 2, 4, 2, 2, 4};
	int			i;

	total = 0;
	op_index = 0;
	i = 0;
	if (file->label != NULL && file->instruct == NULL)
		return (0);
	while (ft_strcmp(g_op_tab[op_index].name, file->instruct))
		op_index++;
	total = 2 + g_op_tab[op_index].octal_code - 1;
	while (i < 3)
	{
		if (file->type_param[i] == 1 || file->type_param[i] == 2)
			total += file->type_param[i];
		else if (file->type_param[i] == 4)
			total += dir_size[op_index];
		i++;
	}
	return (total);
}

int				ft_check_validity_parser(t_asm *info)
{
	int			total;
	t_parse		*nav;

	nav = info->file;
	total = 0;
	ft_set_gerror(0, 0, 0, NULL);
	if (check_instructions(info) == -1)
		return (-1);
	if (get_lst_label(info) == -1)
		return (-1);
	if (check_and_set_params(info) == -1)
		return (-1);
	while (nav)
	{
		total += ft_get_size(nav);
		nav = nav->next;
	}
	info->header->prog_size = (unsigned int)total;
	return (1);
}
