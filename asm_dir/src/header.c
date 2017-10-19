/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drimo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 21:35:42 by drimo             #+#    #+#             */
/*   Updated: 2017/10/06 00:00:55 by drimo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

char			ft_fill_header_content_s(t_asm *info)
{
	char		*line;
	char		error;

	error = 0;
	line = NULL;
	while (get_next_line(info->fd_s, &line) > 0)
	{
		error = ft_is_header(line, info);
		g_ligne++;
		if (error > 0)
			free(line);
		if (error <= 0)
			break ;
	}
	error = ft_manage_error_header(error, info, line);
	if (error == 0)
		ft_get_content(line, info);
	return (error);
}

char			ft_is_header(char *line, t_asm *info)
{
	int			i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == COMMENT_CHAR)
		return (1);
	else if (!(ft_strncmp((line + i), NAME_CMD_STRING, 5)))
		return (ft_is_name(line, info));
	else if (!(ft_strncmp((line + i), COMMENT_CMD_STRING, 8)))
		return (ft_is_comment(line, info));
	else if (line[i] == '\0')
		return (1);
	else if (!(ft_strncmp((line + i), ".", 1)))
		return (-4);
	return (0);
}

void			ft_get_content(char *line, t_asm *info)
{
	char		*str;

	ft_parser(info, line);
	free(line);
	while (get_next_line(info->fd_s, &str) > 0)
	{
		if (ft_is_empty(str))
			g_ligne++;
		else
			ft_parser(info, str);
		free(str);
	}
}

char			ft_copy_name(char *line, t_asm *info)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] == '\0')
		return (-3);
	else
		i++;
	while (line[i] && line[i] != '"')
	{
		info->header->prog_name[count] = line[i];
		count++;
		if (count == PROG_NAME_LENGTH)
			return (-6);
		i++;
	}
	if (!line[i])
		return (-3);
	info->name_count++;
	return (1);
}

char			ft_copy_comment(char *line, t_asm *info)
{
	int			i;
	int			count;

	count = 0;
	i = 0;
	while (line[i] && line[i] != '"')
		i++;
	if (line[i] == '\0')
		return (-3);
	else
		i++;
	while (line[i] && line[i] != '"')
	{
		info->header->comment[count] = line[i];
		count++;
		if (count == COMMENT_LENGTH)
			return (-7);
		i++;
	}
	if (!line[i])
		return (-3);
	info->comment_count++;
	return (1);
}
