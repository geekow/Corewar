/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:21:21 by jjaouen           #+#    #+#             */
/*   Updated: 2017/10/07 05:34:49 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int				ft_reverse_memory_int(int vle, int size)
{
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	size = ((size - 1) * 8);
	while (i <= size)
	{
		ret |= ((vle >> (size - i) & 0xff)) << i;
		i += 8;
	}
	return (ret);
}

char			ft_is_empty(char *line)
{
	int			i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == COMMENT_CHAR)
		return (1);
	else
		return (0);
}

void			add_label_to_lst(t_asm *info, char *label, int line)
{
	t_lab		*lab;
	t_lab		*nav;

	nav = info->lst_label;
	lab = ft_memallocexit(sizeof(t_lab));
	lab->name_label = label;
	lab->line_label = line;
	lab->vle_label = -1;
	lab->next = NULL;
	if (nav == NULL)
		info->lst_label = lab;
	else
	{
		while (nav->next)
			nav = nav->next;
		nav->next = lab;
	}
}

int				ft_valid_num(char *str)
{
	int			i;

	i = -1;
	if (str[0] == '\0')
		return (-1);
	if (str[0] == '-')
	{
		i++;
		if (str[1] == '\0')
			return (-1);
	}
	while (str[++i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (-1);
	}
	return (1);
}

char			**ft_apply_trim_tab(char **tab)
{
	int			i;
	char		*tmp;

	i = -1;
	if (tab == NULL)
		return (NULL);
	while (tab[++i])
	{
		tmp = ft_strtrim_all(tab[i]);
		free(tab[i]);
		tab[i] = tmp;
	}
	return (tab);
}
