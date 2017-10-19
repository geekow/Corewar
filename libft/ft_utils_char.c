/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 09:15:49 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/10 07:18:04 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_s_null(char **char_arg, t_var *vari, int *f)
{
	if (VP != -1 && VP < 6)
	{
		*char_arg = ft_memallocexit(VP + 1);
		*f = 42;
		ft_strncpy(*char_arg, "(null)", VP);
	}
	else if ((vari->safes1 = 1))
		*char_arg = ft_strdup("(null)");
}

void		ft_add_s(char **dst, char **char_arg, int size, t_var *vari)
{
	int		k;

	k = -1;
	if (VM == 0 && vari->safes == 0)
	{
		while (((*char_arg)[++k]) != '\0' && k != VP)
			((*dst)[++size - vari->js - 1]) = ((*char_arg)[k]);
		if (VZ == 1 && (k = -1))
			while (((*dst)[++k]))
				if (((*dst)[k]) == ' ')
					((*dst)[k]) = '0';
	}
	else if (VM == 1 && vari->safes == 0)
		while (((*char_arg)[++k]) && k != VP)
			((*dst)[k]) = ((*char_arg)[k]);
}

void		ft_free_schar(t_var *vari, char **char_arg, int f, int safe1)
{
	if (*char_arg != NULL && (VP != -1 && VF != -1 && VZ == -1) && f == 42)
		ft_memdel((void **)char_arg);
	else if ((VT == 'S' || VL == 'l'))
		ft_memdel((void **)char_arg);
	else if ((f == 42 && VP != -1) || ((ft_strcmp(*char_arg, "(null)") == 0)
				&& f == 42))
		ft_memdel((void **)char_arg);
	else if (safe1 == 1)
		ft_memdel((void **)char_arg);
}

void		ft_process_uni(char **char_arg, t_var *vari)
{
	int		*uni_char;

	uni_char = (int*)va_arg(vari->args, wchar_t*);
	if (!(uni_char))
	{
		if (VP != -1 && VP < 6)
		{
			*char_arg = ft_memallocexit(VP + 1);
			ft_strncpy(*char_arg, "(null)", VP);
		}
		else
			*char_arg = ft_strdup("(null)");
	}
	else
		ft_apply_s_uni(vari, uni_char, char_arg);
}
