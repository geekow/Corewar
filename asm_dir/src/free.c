/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:27:07 by jjaouen           #+#    #+#             */
/*   Updated: 2017/07/25 23:27:13 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

t_asm			*ft_free_parser(t_asm *info)
{
	t_parse		*parse_nxt;

	parse_nxt = info->file;
	if (parse_nxt != NULL)
	{
		while (parse_nxt)
		{
			info->file = parse_nxt;
			if (info->file->label != NULL)
				ft_strdel(&(info->file->label));
			if (info->file->instruct != NULL)
				ft_strdel(&(info->file->instruct));
			if (info->file->param != NULL)
				ft_free_words_tables(&(info->file->param));
			parse_nxt = info->file->next;
			free(info->file);
		}
	}
	return (info);
}

t_asm			*ft_free_label(t_asm *info)
{
	t_lab		*lab_nxt;

	lab_nxt = info->lst_label;
	if (lab_nxt != NULL)
	{
		while (lab_nxt)
		{
			info->lst_label = lab_nxt;
			lab_nxt = info->lst_label->next;
			free(info->lst_label);
		}
	}
	return (info);
}

t_asm			*ft_free_all(t_asm *info)
{
	if (info == NULL)
		return (NULL);
	if (info->header != NULL)
		free(info->header);
	ft_strdel(&(info->file_name));
	info = ft_free_parser(info);
	info = ft_free_label(info);
	free(info);
	info = NULL;
	return (info);
}
