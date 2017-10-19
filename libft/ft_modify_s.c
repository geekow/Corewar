/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:15:27 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/10 07:15:00 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_unicode_s(int c)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	str = ft_memallocexit(5);
	if (c > 127 && (size = 2))
	{
		if (c > 2047 && (size = 3))
		{
			if (c > 65535 && (++size) && (str[i++] = ((c >> 18) & 7) | 240))
				str[i++] = ((c >> 12) & 63) | 128;
			else
				str[i++] = ((c >> 12) & 15) | 224;
			str[i++] = ((c >> 6) & 63) | 128;
		}
		else
			str[i++] = ((c >> 6) & 31) | 192;
		str[i++] = (c & 63) | 128;
		str[i] = '\0';
		return (str);
	}
	else if ((str[0] = c) && (str[1] += '\0'))
		return (str);
	return (str);
}

void		ft_apply_s_uni(t_var *vari, int *uni_char, char **char_arg)
{
	char	*tmp2;
	int		k;
	char	*tmp;
	int		vpuni;

	k = -1;
	tmp2 = NULL;
	tmp = NULL;
	vpuni = 0;
	if (!(uni_char[0]))
		tmp = ft_strnew(1);
	while (uni_char[++k])
	{
		tmp2 = ft_unicode_s(uni_char[k]);
		if ((vpuni += ft_strlen(tmp2)) && VP > 0 && vpuni > VP)
			break ;
		if (!(tmp))
			tmp = ft_strdup(tmp2);
		else
			tmp = ft_strjoinf(tmp, tmp2, 1);
		ft_strdel(&tmp2);
	}
	*char_arg = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}

int			ft_get_size_str(t_var *vari, char **dst, char **char_arg)
{
	int		size;

	size = ft_strlen(*char_arg);
	if (VP < size)
		size = VP;
	if (size < VF)
		size = VF;
	if (VP == -1 && VF != -1 && VF < ft_strlen(*char_arg))
		size = ft_strlen(*char_arg);
	*dst = ft_memallocexit(size + 1);
	ft_memset(*dst, ' ', size);
	return (size);
}

void		ft_modify_s(t_var *vari, char **dst)
{
	char	*char_arg;
	int		size;
	int		f;

	f = 0;
	char_arg = NULL;
	size = 0;
	if (VL != 'l' && VT != 'S')
		char_arg = va_arg(vari->args, char*);
	else
		ft_process_uni(&char_arg, vari);
	if (char_arg == NULL)
		ft_s_null(&char_arg, vari, &f);
	if ((VF != -1 || VP != -1 || VZ != 0))
		size = ft_get_size_str(vari, dst, &char_arg);
	else if ((vari->safes = 1) && (size += ft_strlen(char_arg)))
		*dst = ft_strdup(char_arg);
	if (VP > ft_strlen(char_arg) || (VF > ft_strlen(char_arg) && VP == -1))
		vari->js = ft_strlen(char_arg);
	else if (VP != -1)
		vari->js = VP;
	else
		vari->js = ft_strlen(char_arg);
	ft_add_s(dst, &char_arg, size, vari);
	ft_free_schar(vari, &char_arg, f, vari->safes1);
}
