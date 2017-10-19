/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 22:12:25 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/10 08:06:09 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_modify_arg(t_var *vari)
{
	char	*dst;

	dst = NULL;
	if (VT == 'p' && (VT = 'x'))
		if (VT == 'x' && (VH = 2))
			VL = 'l';
	if (VT != 'd' && VT != 'D' && VT != 'i' && VT != 'o' &&
	VT != 'O' && VT != 'u' && VT != 'U' && VT != 'x' && VT != 'X' && VT != 'c'
	&& VT != 'C' && VT != 's' && VT != 'S' && VT != '0')
	{
		VL = (VL != '0') ? '0' : VL;
		ft_modify_c(vari, &dst);
	}
	if (VT == 'd' || VT == 'i' || VT == 'D' || VT == 'o' || VT == 'O' ||
			VT == 'u' || VT == 'U' || VT == 'x' || VT == 'X')
		ft_modify_int(vari, &dst);
	else if (VT == 'c' || VT == 'C')
		ft_modify_c(vari, &dst);
	else if (VT == 's' || VT == 'S')
		ft_modify_s(vari, &dst);
	add_arg_modified(vari, &dst);
}

char	ft_strchrstr(const char *s, int i, char *convert)
{
	int		j;

	i++;
	while (s[i] != '\0')
	{
		j = 0;
		while (convert[j] != '\0')
		{
			if (s[i] == convert[j])
				return (s[i]);
			j++;
		}
		i++;
	}
	return ('0');
}

void	ft_init(t_var *vari)
{
	vari->type = '0';
	vari->flag_hash = 0;
	vari->flag_zero = 0;
	vari->flag_space = 0;
	vari->flag_plus = 0;
	vari->flag_moins = 0;
	vari->flag_long = '0';
	vari->flag_preci = -1;
	vari->flag_field = -1;
	vari->argispos = 0;
	vari->js = 0;
	vari->safes = 0;
	vari->safes1 = 0;
}

int		ft_add_args(const char *s, t_var *vari, int i)
{
	int		end;

	ft_init(vari);
	if ((vari->type = ft_strchrstr(s, i, "sSpdDioOuUxXcC%aAbBeEfFgGHJkKLmMnNPqQ\
rRtTvVyYZ!\"$&'(),/:;<=>?@[]\\^_{}~`\n\t\n\r\v")) == '0')
		vari->error = '0';
	if (VT == '%')
		i++;
	end = ft_strchrint((s + i), vari->type);
	if (VT != '0')
	{
		ft_find(vari, s, i);
		ft_add_modify_arg(vari);
	}
	if (VT == '%' || VT == '0')
		end++;
	ft_init(vari);
	return (end + 1);
}

int		ft_printf(const char *s, ...)
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
	write(1, vari->dst, vari->added_char);
	i = vari->added_char;
	ft_strdel(&vari->dst);
	free(vari);
	return (i);
}
