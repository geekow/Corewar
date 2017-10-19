/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 23:02:51 by jjaouen           #+#    #+#             */
/*   Updated: 2017/10/07 05:41:11 by drimo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int				ft_set_gerror(int error, int line_error, int param_error,
		t_parse *error_line)
{
	g_error[0].error = error;
	g_error[0].line_error = line_error;
	if (param_error != -42)
		g_error[0].param_error = param_error;
	g_error[0].error_line = error_line;
	return (1);
}

void			ft_write_error_two(t_asm *info)
{
	if (g_error[0].error == PARAM_UNKNOW)
		ft_dprintf(2, "%s%s:%s %sError:%s %sLine %d:%s Parameter %d : \"%s\" \
from instruct \"%s\" is unknow.\n",
				KWHT, info->original_name, KNRM, KRED, KNRM, KGRN,
				g_error[0].line_error, KNRM, g_error[0].param_error,
				g_error[0].error_line->param[g_error[0].param_error - 1],
				g_error[0].error_line->instruct);
	if (g_error[0].error == PARAM_NOT_MATCH)
		ft_dprintf(2, "%s%s:%s %sError:%s %sLine %d:%s Parameter %d for \
instruct \"%s\" is wrong.\n",
				KWHT, info->original_name, KNRM, KRED, KNRM, KGRN,
				g_error[0].line_error,
				KNRM, g_error[0].param_error, g_error[0].error_line->instruct);
	if (g_error[0].error == PARAM_BIG)
		ft_dprintf(2, "%s%s:%s %sError:%s %sLine %d:%s Too many or less \
parameters for instruct \"%s\".\n",
				KWHT, info->original_name, KNRM, KRED, KNRM, KGRN,
				g_error[0].line_error, KNRM, g_error[0].error_line->instruct);
}

int				ft_write_error(t_asm *info)
{
	char		*tmp;

	tmp = NULL;
	if (g_error[0].error == INSTRUCT_NOEXIST)
	{
		if (g_error[0].error_line->instruct == NULL)
			tmp = NULL;
		else
			tmp = (g_error[0].error_line->instruct[0] == '\0') ? (NULL) :
				g_error[0].error_line->instruct;
		ft_dprintf(2, "%s%s:%s %sError:%s %sLine %d:%s Instruct \"%s\" \
is not allowed.\n",
				KWHT, info->original_name, KNRM, KRED, KNRM, KGRN,
				g_error[0].error_line->line, KNRM, tmp);
	}
	if (g_error[0].error == LABEL_CHAR_ERR)
		ft_dprintf(2, "%s%s:%s %sError:%s %sLine %d:%s Label \"%s\" \
has forbidden character.\n",
				KWHT, info->original_name, KNRM, KRED, KNRM, KGRN,
				g_error[0].line_error, KNRM, g_error[0].error_line->label);
	else
		ft_write_error_two(info);
	return (1);
}

int				write_unxpected(t_asm *info, char *line)
{
	ft_dprintf(2, "%s%s:%s %sError:%s %sLine %d:%s Unexpected \
expression: \"%s\"\n", KWHT, info->original_name, KNRM, KRED,
		KNRM, KGRN, g_ligne, KNRM, line);
	ft_strdel(&line);
	ft_free_gnl(info->fd_s);
	return (1);
}

char			ft_manage_error_header(char error, t_asm *info, char *line)
{
	if (error == -1)
		ft_dprintf(2, "%s%s:%s %sError:%s Multiple name given\n",
				KWHT, info->original_name, KNRM, KRED, KNRM);
	else if (error == -2 || error == -3 || error == -4)
		ft_print_manage_error_header(error, info, line);
	else if (error == -6 || error == -7)
		ft_print_manage_error_header_2(error, info);
	else if (error == 0)
	{
		if ((info->name_count != 1 || info->comment_count != 1) &&
		write_unxpected(info, line))
			return (-5);
		else
			return (0);
	}
	else if (error == 1)
	{
		ft_dprintf(2, "%s%s:%s %sError:%s %sLine %d:%s \
Something wrong happened: \"%s\"\n", KWHT, info->original_name, KNRM, KRED,
	KNRM, KGRN, g_ligne, KNRM, line);
	}
	free(line);
	(error != 0) ? ft_free_gnl(info->fd_s) : 1;
	return (error);
}
