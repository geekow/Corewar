/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 06:37:19 by jjaouen           #+#    #+#             */
/*   Updated: 2017/07/25 23:08:34 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void			ft_init_asm_struct(t_asm *info, int fd_s, char *name)
{
	info->file_name = ft_strjoinf(ft_strsub(name, 0,
				ft_strlen(name) - 2), ".cor", 1);
	info->fd_s = fd_s;
	info->original_name = name;
	info->fd_c = -1;
	info->header = ft_memallocexit(sizeof(t_header));
	info->header->magic = ft_reverse_memory_int(COREWAR_EXEC_MAGIC, 4);
	info->name_count = 0;
	info->comment_count = 0;
	info->file = NULL;
	info->lst_label = NULL;
}

t_asm			*ft_asm_file(char *name, t_asm *info)
{
	int			fd_s;

	if (name[ft_strlen(name) - 2] == '.' && name[ft_strlen(name) - 1] == 's')
	{
		if ((fd_s = open(name, O_RDONLY)) != -1)
			info = (t_asm*)ft_memallocexit(sizeof(t_asm));
		else if (ft_dprintf(2,
					"%s%s:%s %sFatal Error:%s %sline 0:%s %s not found.\n",
					KWHT, name, KNRM, KRED, KNRM, KGRN, KNRM, name))
			return (info);
		ft_init_asm_struct(info, fd_s, name);
		if (ft_fill_header_content_s(info))
			return (info);
		if (ft_check_validity_parser(info) == -1 && ft_write_error(info))
			return (info);
		write_file(info);
	}
	else if (ft_dprintf(2,
				"%s%s:%s %sFatal Error:%s %sline 0:%s Extension must be .s.\n",
				KWHT, name, KNRM, KRED, KNRM, KGRN, KNRM, name))
		return (info);
	close(info->fd_c);
	ft_printf("%sSUCESS%s: %s%s%s was created.\n", KGRN, KNRM, KWHT,
			info->file_name, KNRM);
	return (info);
}

int				main(int ac, char **av)
{
	int			i;
	t_asm		*info;

	info = NULL;
	i = 0;
	g_ligne = 0;
	if (ac > 1 && av)
		while (++i != ac)
		{
			info = ft_asm_file(av[i], info);
			info = ft_free_all(info);
			ft_set_gerror(0, 0, 0, NULL);
		}
	else
		ft_dprintf(2, "Usage : ./asm <champion.s> ...\n");
	return (0);
}
