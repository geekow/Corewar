/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:01:06 by jjaouen           #+#    #+#             */
/*   Updated: 2017/10/05 23:07:45 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int				get_lst_label(t_asm *info)
{
	t_parse		*nav;
	int			i;

	i = -1;
	nav = info->file;
	while (nav)
	{
		if (nav->label != NULL)
		{
			while (nav->label[++i])
			{
				if (ft_strchrint(LABEL_CHARS, nav->label[i]) == -1)
				{
					ft_set_gerror(LABEL_CHAR_ERR, nav->line, 0,
							(t_parse*)nav);
					return (-1);
				}
				else if (nav->label[i + 1] == '\0')
					add_label_to_lst(info, nav->label, nav->line);
			}
			i = -1;
		}
		nav = nav->next;
	}
	return (1);
}

int				check_instructions(t_asm *info)
{
	t_parse		*nav;
	int			i;

	i = -1;
	nav = info->file;
	while (nav)
	{
		while (++i < 17)
		{
			if (i == 16 && nav->instruct != NULL)
			{
				ft_set_gerror(INSTRUCT_NOEXIST, 0, 0, (t_parse*)nav);
				return (-1);
			}
			if (nav->instruct != NULL)
				if (ft_strcmp(g_op_tab[i].name, nav->instruct) == 0 ||
				nav->instruct[0] == COMMENT_CHAR)
					break ;
		}
		i = -1;
		nav = nav->next;
	}
	return (1);
}

int				ft_get_type(char *str)
{
	int			i;

	i = 0;
	if (str[0] == 'r')
	{
		while (str[++i])
			if (ft_isdigit(str[i]) == 0 || i > 2)
				return (-1);
		return (T_REG);
	}
	else if (str[0] == '%')
	{
		if (str[1] == ':')
			return (5);
		else if (ft_valid_num(str + 1) == 1)
			return (4);
		else
			return (-1);
	}
	else if (str[0] == ':')
		return (3);
	else if (ft_valid_num(str) == 1)
		return (IND_SIZE);
	return (-1);
}

int				ft_check_and_set_params_2(t_asm *info, t_parse *nav, int *i)
{
	if ((PARAM == NULL || PARAM0 == '\0' || ft_tablen(PARAM) !=
				g_op_tab[get_op_index(nav->instruct)].nb_param) &&
			ft_set_gerror(PARAM_BIG, nav->line, *i + 1, (t_parse*)nav))
		return (-1);
	while (++(*i) != ft_tablen(nav->param))
	{
		if (nav->param[*i] == NULL)
			nav->type_param[*i] = 0;
		else if ((nav->type_param[*i] = ft_get_type(nav->param[*i])) == -1 &&
						ft_set_gerror(PARAM_UNKNOW,
						nav->line, *i + 1, (t_parse*)nav))
			return (-1);
	}
	if (ft_check_match_param(info, nav) == -1 &&
			ft_set_gerror(PARAM_NOT_MATCH, nav->line, -42, (t_parse*)nav))
		return (-1);
	return (1);
}

int				check_and_set_params(t_asm *info)
{
	t_parse		*nav;
	int			i;
	int			error;

	error = 0;
	nav = info->file;
	while (nav)
	{
		i = -1;
		if (nav->label != NULL && nav->instruct == NULL)
			i = (int)i;
		else
		{
			if (ft_check_and_set_params_2(info, nav, &i) == -1)
				return (-1);
		}
		nav = nav->next;
	}
	return (1);
}
