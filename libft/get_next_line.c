/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 05:33:40 by jjaouen           #+#    #+#             */
/*   Updated: 2017/05/08 10:19:18 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "./libft.h"

void	ft_lstdelelem(t_list **tab, t_list *del)
{
	t_list *tmp1;
	t_list *tmp2;

	tmp1 = *tab;
	tmp2 = tmp1;
	if (tmp2 == del)
	{
		*tab = tmp2->next;
		ft_strdel((&((t_gl*)tmp2->content)->s));
		ft_memdel(&(tmp2->content));
		free(tmp2);
		return ;
	}
	while (tmp1->next && tmp1->next != del)
		tmp1 = tmp1->next;
	if (!(tmp1->next))
		return ;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	free(tmp2->content);
	free(tmp2);
}

t_list	*isfd(const int fd, t_list **tab)
{
	t_list	*temp;
	t_gl	*content;

	temp = *tab;
	while (temp)
	{
		if (((t_gl*)(temp->content))->fd == fd)
			break ;
		temp = temp->next;
	}
	if (!temp)
	{
		if (!(content = (t_gl *)malloc(sizeof(t_gl))))
			return (NULL);
		temp = ft_lstnew(content, sizeof(t_gl ));
		free(content);
		ft_lstadd(tab, temp);
		((t_gl *)(temp->content))->fd = fd;
		((t_gl *)(temp->content))->s = ft_strnew(0);
	}
	return (temp);
}

int		splitgnl(char **ln, t_list *tp, char *tm, t_list **tab)
{
	t_gl *temp;

	temp = (t_gl *)(tp->content);
	if (!tm && temp->s[0] == '\0')
	{
		ft_lstdelelem(tab, tp);
		free(tm);
		return (0);
	}
	if (tm)
	{
		*ln = ft_strsub(temp->s, 0, tm - temp->s);
		temp->s = ft_strcpy(temp->s, ++tm);
	}
	else
	{
		*ln = ft_strdup(temp->s);
		free(temp->s);
		temp->s = ft_strdup("\0");
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*tab = NULL;
	t_list			*tmp;
	t_vark			v;
	int				ret;

	v.tmp = NULL;
	if (fd < 0 || !line || (read(fd, v.tmp, 0)) == -1 || BUFF_SIZE <= 0)
		return (-1);
	if (!(v.buff = (char *)malloc(BUFF_SIZE + 1)))
		return (-1);
	*line = NULL;
	ret = 0;
	tmp = isfd(fd, &tab);
	v.gnl = (t_gl *)(tmp->content);
	(v.tmp = ft_strchr((v.gnl)->s, '\n'));
	while (line && !v.tmp && (ret = read(fd, v.buff, BUFF_SIZE)) > 0)
	{
		v.buff[ret] = '\0';
		if ((v.tmp = ft_strjoin((v.gnl)->s, v.buff)))
			((v.gnl)->s) ? free((v.gnl)->s) : NULL;
		(v.gnl)->s = v.tmp;
		v.tmp = ft_strchr((v.gnl)->s, '\n');
	}
	v.buff ? free(v.buff) : NULL;
	return (ret == (-1) ? -1 : splitgnl(line, tmp, v.tmp, &tab));
}
