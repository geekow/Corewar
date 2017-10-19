/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 20:56:40 by jjaouen           #+#    #+#             */
/*   Updated: 2017/10/05 21:43:40 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int				get_op_index(char *instruct)
{
	int			i;

	i = 0;
	while (ft_strcmp(instruct, g_op_tab[i].name) != 0)
		i++;
	return (i);
}

int				ft_check_match_param(t_asm *info, t_parse *nav)
{
	int			i;
	int			index;

	i = -1;
	index = 0;
	while (g_op_tab[index].name &&
			ft_strcmp(nav->instruct, g_op_tab[index].name))
		index++;
	while (++i < 3)
	{
		if (ft_assign_type_value(info, nav, i) &&
				(g_error[0].param_error = i + 1))
			return (-1);
	}
	i = -1;
	while (++i < 3)
	{
		if (ft_matching_param(nav, i, index) &&
				(g_error[0].param_error = i + 1))
			return (-1);
	}
	return (0);
}

char			ft_assign_type_value(t_asm *info, t_parse *nav, int i)
{
	if (nav->type_param[i] == 5)
	{
		if (ft_label_exist(nav->param[i] + 2, info->lst_label))
			nav->type_param[i] = 4;
		else
			return (-1);
	}
	else if (nav->type_param[i] == 3)
	{
		if (ft_label_exist(nav->param[i] + 1, info->lst_label))
			nav->type_param[i] = 2;
		else
			return (-1);
	}
	return (0);
}

char			ft_label_exist(char *label, t_lab *list)
{
	t_lab		*nav;

	nav = list;
	while (nav)
	{
		if (!strcmp(nav->name_label, label))
			return (1);
		nav = nav->next;
	}
	return (0);
}

char			ft_matching_param(t_parse *nav, int i, int index)
{
	int			my_param;

	my_param = 0;
	if (nav->type_param[i] == 2)
	{
		my_param = 4;
		if (my_param != (g_op_tab[index].type_param[i] & my_param))
			return (-1);
	}
	else if (nav->type_param[i] == 4)
	{
		my_param = 2;
		if (my_param != (g_op_tab[index].type_param[i] & my_param))
			return (-1);
	}
	else
	{
		if (nav->type_param[i] != (g_op_tab[index].type_param[i] &
					nav->type_param[i]))
			return (-1);
	}
	return (0);
}
