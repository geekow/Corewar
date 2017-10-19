/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_vle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:27:36 by jjaouen           #+#    #+#             */
/*   Updated: 2017/07/25 23:32:00 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int				ft_get_target(t_asm *info, char *str)
{
	t_lab		*nav_lab;
	int			target;

	nav_lab = info->lst_label;
	target = 0;
	while (nav_lab)
	{
		if (ft_strcmp(str, nav_lab->name_label) == 0)
		{
			target = nav_lab->line_label;
			break ;
		}
		nav_lab = nav_lab->next;
	}
	return (target);
}

int				ft_return_value(t_parse *nav, int line, int target, int code)
{
	int			result;

	result = 0;
	if (code == 0)
	{
		while (nav->line != target)
			nav = nav->next;
		while (nav->line != line)
		{
			result += ft_get_size(nav);
			nav = nav->next;
		}
		return (result * -1);
	}
	else
	{
		while (nav->line != line)
			nav = nav->next;
		while (nav->line != target)
		{
			result += ft_get_size(nav);
			nav = nav->next;
		}
		return (result);
	}
}

int				ft_get_vle_label(char *str, int line, t_asm *info)
{
	t_parse		*nav;
	int			target;
	int			result;

	nav = info->file;
	target = ft_get_target(info, str);
	result = 0;
	if (line == target)
		return (0);
	else if (line > target)
		result = ft_return_value(nav, line, target, 0);
	else if (line < target)
		result = ft_return_value(nav, line, target, 1);
	return (result);
}
