/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 21:40:14 by jjaouen           #+#    #+#             */
/*   Updated: 2017/10/02 18:40:13 by drimo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

char			*ft_get_instruct(char *str, char *label)
{
	int			start;
	int			end;
	char		*ret;
	int			skip;

	end = -1;
	if (label != NULL && str[ft_strlen(str) - 1] == ':' &&
			ft_strlen(str) == (ft_strlen(label) + 1))
		return (NULL);
	skip = (label != NULL && str[ft_strchrint(str, ':') + 1] != ' ' &&
	str[ft_strchrint(str, ':') + 1] != '\t') ? 1 : 2;
	start = (label == NULL) ? 0 : ft_strlen(label) + skip;
	end = (label == NULL) ? ft_strchrint(str, ' ') :
		ft_strchrint(str + start, ' ');
	if (end == -1)
		end = ft_strlen(str);
	ret = ft_strsub(str, start, end);
	if (ret[0] == COMMENT_CHAR)
		return (NULL);
	else
		return (ret);
}

char			*ft_get_label(char *str)
{
	char		*label;
	int			i;
	int			count_space;

	i = -1;
	label = NULL;
	count_space = 0;
	while (str[++i])
	{
		if (str[i] == ' ')
			count_space++;
		if (str[i] == LABEL_CHAR && count_space == 0)
			return (ft_strsub(str, 0, i));
	}
	return (label);
}

void			ft_lstparse_push(t_parse **file, t_parse *new)
{
	t_parse		*tmp;

	tmp = *file;
	if (*file == NULL)
		*file = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

char			**ft_get_param(char *tmp, char *label, char *instruct)
{
	int			start;
	char		*str;
	int			end;
	char		**result;
	char		*temp;

	if (instruct == NULL || instruct[0] == '\0' ||
			ft_strlen(instruct) == ft_strlen(tmp))
		return (NULL);
	start = (label == NULL) ? ft_strchrint(tmp, ' ') + 1 :
		ft_strlen(label) + ft_strlen(instruct) + 2;
	(tmp[start] == ' ') ? start++ : 1;
	str = ft_strsub(tmp, start, (ft_strlen(tmp) - start));
	end = (ft_strchrint(str, COMMENT_CHAR) == -1) ? ft_strlen(str) :
		ft_strchrint(str, COMMENT_CHAR);
	temp = ft_strsubf(str, 0, end);
	result = ft_strsplit(temp, ',');
	ft_strdel(&temp);
	return (result);
}

void			ft_parser(t_asm *info, char *line)
{
	t_parse		*new;
	char		*tmp;

	tmp = ft_strtrim_all(line);
	new = NULL;
	new = (t_parse*)ft_memallocexit(sizeof(t_parse));
	new->next = NULL;
	new->line = g_ligne++;
	new->label = ft_get_label(tmp);
	new->instruct = ft_get_instruct(tmp, new->label);
	new->param = ft_apply_trim_tab(ft_get_param(tmp, new->label,
				new->instruct));
	ft_lstparse_push(&(info->file), new);
	free(tmp);
}
