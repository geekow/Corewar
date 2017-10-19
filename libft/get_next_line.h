/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 10:19:27 by jjaouen           #+#    #+#             */
/*   Updated: 2017/05/08 10:19:32 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

int					get_next_line(const int fd, char **line);

typedef struct		s_gl
{
	char			*s;
	int				fd;
}					t_gl;

typedef struct		s_vark
{
	char			*buff;
	char			*tmp;
	t_gl			*gnl;
}					t_vark;

#endif
