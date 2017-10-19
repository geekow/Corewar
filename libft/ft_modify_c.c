/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:13:43 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/10 07:13:36 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_process_c(t_var *vari, char **char_arg, char **dst, int ch)
{
	int		siz;
	int		k;

	k = -1;
	if ((VT == 'C' || VL == 'l'))
		ft_apply_unicode(char_arg, ch);
	else if ((*char_arg = ft_memallocexit(2)) && (((*char_arg)[0]) += ch))
		((*char_arg)[1]) = '\0';
	siz = get_str_arg(vari, dst, char_arg);
	if (VT != 'C' && VL != 'l')
		ft_notunicode(vari, dst, ch, siz);
	if (VZ == 1 && VF != -1)
		ft_replace_char(*dst, ' ', '0');
	if (VT == 'C' || VL == 'l')
	{
		if (VM == 0)
			while (((*char_arg)[++k]) != '\0')
				((*dst)[++siz - (ft_strlen(*char_arg)) - 1]) = ((*char_arg)[k]);
		else
			while (((*char_arg)[++k]))
				((*dst)[k]) = ((*char_arg)[k]);
	}
}

void		ft_notunicode(t_var *vari, char **dst, int ch, int size)
{
	if (VM == 0)
	{
		if (size == 0)
			((*dst)[size]) = ch;
		else
			((*dst)[size - 1]) = ch;
	}
	else
		((*dst)[0]) = ch;
	((*dst)[size]) = '\0';
}

void		ft_apply_unicode(char **charg, int cu)
{
	char	str[5];
	int		i;
	int		size;

	i = 0;
	size = 1;
	if (cu > 127 && (size = 2))
	{
		if (cu > 2047 && (size = 3))
		{
			if (cu > 65535 && (++size) && (str[i++] = ((cu >> 18) & 7) | 240))
				str[i++] = ((cu >> 12) & 63) | 128;
			else
				str[i++] = ((cu >> 12) & 15) | 224;
			str[i++] = ((cu >> 6) & 63) | 128;
		}
		else
			str[i++] = ((cu >> 6) & 31) | 192;
		str[i++] = (cu & 63) | 128;
		str[size] = '\0';
		*charg = ft_strdup(str);
	}
	else if ((*charg = ft_memallocexit(size + 1)) && ((*charg)[size - 1] += cu))
		((*charg)[size]) = '\0';
}

int			get_str_arg(t_var *vari, char **dst, char **char_arg)
{
	int		size;

	size = ft_strlen(*char_arg);
	if (size < VF)
		size = VF;
	*dst = ft_memallocexit(size + 1);
	ft_memset(*dst, ' ', size);
	return (size);
}

void		ft_modify_c(t_var *vari, char **dst)
{
	char	*char_arg;
	int		ch;

	char_arg = NULL;
	ch = 0;
	if (VL != 'l' || VT == 'C')
		VL = '0';
	if (VT != 'd' && VT != 'D' && VT != 'i' && VT != 'o' && VT != 'O'
			&& VT != 'u' && VT != 'U' && VT != 'x' && VT != 'X' && VT != 'c'
			&& VT != 'C' && VT != 's' && VT != 'S')
		ch = VT;
	else if (VL != 'l' && VT != 'C')
		ch = (unsigned char)va_arg(vari->args, int);
	else
		ch = (int)va_arg(vari->args, wchar_t);
	if (ch == 0)
		vari->backz++;
	ft_process_c(vari, &char_arg, dst, ch);
	ft_strdel(&char_arg);
}
