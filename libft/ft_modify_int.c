/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 21:36:54 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/01 11:05:30 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_modify_unsignedarg(t_var *vari, char **dst,
		uintmax_t arg)
{
	char			*char_arg;
	int				i;

	i = -1;
	if (arg > 0)
		vari->argispos = 1;
	if (VT == 'd' || VT == 'D' || VT == 'i' || VT == 'u' || VT == 'U')
		char_arg = ft_itoa_uimt(arg);
	else if (VT == 'o' || VT == 'O')
		char_arg = ft_itoa_base_uimt(arg, 8);
	else if (VT == 'x' || VT == 'X')
		char_arg = ft_itoa_base_uimt(arg, 16);
	if (VT == 'X')
		while (char_arg[++i] != '\0')
			char_arg[i] = ft_toupper(char_arg[i]);
	ft_apply_modif(vari, dst, &char_arg);
	if (char_arg != NULL)
		free(char_arg);
}

void				ft_modify_signedarg(t_var *vari, char **dst, intmax_t arg)
{
	char			*char_arg;
	int				i;

	i = -1;
	if (arg >= 0)
		vari->argispos = 1;
	if (VT == 'd' || VT == 'D' || VT == 'i')
		char_arg = ft_itoa_imt(arg);
	if (VT == 'u' || VT == 'U')
		char_arg = ft_itoa_uimt((uintmax_t)arg);
	else if (VT == 'o' || VT == 'O')
		char_arg = ft_itoa_base_uimt((uintmax_t)arg, 8);
	else if (VT == 'x' || VT == 'X')
		char_arg = ft_itoa_base_uimt((uintmax_t)arg, 16);
	if (VT == 'X')
		while (char_arg[++i] != '\0')
			char_arg[i] = ft_toupper(char_arg[i]);
	ft_apply_modif(vari, dst, &char_arg);
	if (char_arg != NULL)
		free(char_arg);
}

void				ft_get_type_int_unsigned(t_var *vari, uintmax_t *arg2,
		intmax_t *arg)
{
	if (VL == 'l' || (VT == 'O' || VT == 'U'))
		*arg = (unsigned long int)va_arg(vari->args, long int);
	else if (VL == 'H')
		*arg = (unsigned char)va_arg(vari->args, int);
	else if (VL == 'h')
		*arg = (unsigned short)va_arg(vari->args, int);
	else if (VL == 'L')
		*arg2 = (unsigned long long int)va_arg(vari->args, long long int);
	else if (VL == 'j')
		*arg2 = (uintmax_t)va_arg(vari->args, intmax_t);
	else if (VL == 'z')
		*arg = (size_t)va_arg(vari->args, size_t);
}

void				ft_get_type_int(t_var *vari, uintmax_t *arg2, intmax_t *arg)
{
	if (VT == 'D' || VT == 'd' || VT == 'i')
	{
		if (VL == 'l' || (VT == 'D'))
			*arg = (long int)va_arg(vari->args, long int);
		else if (VL == 'H')
			*arg = (signed char)va_arg(vari->args, int);
		else if (VL == 'h')
			*arg = (short)va_arg(vari->args, int);
		else if (VL == 'L')
			*arg = (long long int)va_arg(vari->args, long long int);
		else if (VL == 'j')
			*arg = (intmax_t)va_arg(vari->args, intmax_t);
		else if (VL == 'z')
			*arg = (ssize_t)va_arg(vari->args, ssize_t);
	}
	else if (VT == 'u' || VT == 'U' || VT == 'o' || VT == 'O' ||
			VT == 'x' || VT == 'X')
		ft_get_type_int_unsigned(vari, arg2, arg);
}

void				ft_modify_int(t_var *vari, char **dst)
{
	uintmax_t		arg2;
	intmax_t		arg;

	arg = 0;
	arg2 = 0;
	if (VT == 'D' || VT == 'U' || VT == 'O')
		VL = 'l';
	if (VL != '0' || VT == 'D' || VT == 'U' || VT == 'O')
		ft_get_type_int(vari, &arg2, &arg);
	else
	{
		if (VT == 'o' || VT == 'u' || VT == 'x' || VT == 'X')
			arg = va_arg(vari->args, unsigned int);
		else
			arg = va_arg(vari->args, int);
	}
	if ((VL == 'j' || VL == 'L') && (VT == 'x' || VT == 'X' || VT == 'o'
	|| VT == 'O' || VT == 'u' || VT == 'U'))
		ft_modify_unsignedarg(vari, dst, arg2);
	else
		ft_modify_signedarg(vari, dst, arg);
}
