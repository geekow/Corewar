/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 22:12:25 by jjaouen           #+#    #+#             */
/*   Updated: 2017/06/06 00:55:00 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dprintf(int fd, const char *s, ...)
{
	t_var	*vari;
	int		i;

	if (!(i = 0) && ft_strlen(s) == 1 && s[0] == '%')
		return (0);
	if (!(vari = (t_var*)ft_memallocexit(sizeof(t_var))))
		return (-1);
	if (ft_initialize(vari) == -1)
		return (-1);
	va_start(vari->args, s);
	while (s[i] != '\0' && i < ft_strlen(s))
	{
		if (s[i] == '%' && s[i + 1] != '\0')
			i += ft_add_args(s, vari, i);
		else
		{
			if (ft_addchar(vari, s[i++]) == -1)
				return (-1);
		}
	}
	write(fd, vari->dst, vari->added_char);
	i = vari->added_char;
	ft_strdel(&vari->dst);
	free(vari);
	return (i);
}
