/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 04:17:46 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/09 10:36:35 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_find_attribut(t_var *vari, const char *s, int start)
{
	int		i;
	int		count_point;
	int		count_digit;

	i = start - 1;
	count_point = 0;
	count_digit = 0;
	while (s[++i] != vari->type)
	{
		if (s[i] == '.')
			count_point++;
		if (ft_isdigit(s[i]) == 1)
			count_digit++;
		if (s[i] == '#')
			vari->flag_hash = 1;
		if (s[i] == '0' && count_point == 0 && count_digit == 1)
			vari->flag_zero = 1;
		if (s[i] == '-')
			vari->flag_moins = 1;
		if (s[i] == '+')
			vari->flag_plus = 1;
		if (s[i] == ' ')
			vari->flag_space = 1;
	}
}

void	ft_find_field(t_var *vari, const char *s, int start)
{
	int		count_digit;

	count_digit = 0;
	while (s[start] != vari->type && vari->flag_field == -1)
	{
		if (s[start] == '.')
			break ;
		if (s[start] == '*' && (VF = (int)va_arg(vari->args, int)))
		{
			if (VF < 0 && (VF = VF * -1))
				VM = 1;
			break ;
		}
		if (ft_isdigit(s[start]) == 1 && ++count_digit)
		{
			if (vari->flag_zero == 1 && count_digit == 1)
				start++;
			if (ft_isdigit(s[start]) && (!(vari->flag_field = 0)))
				while (ft_isdigit(s[start]) == 1 && s[start] != VT)
					vari->flag_field = vari->flag_field * 10 + s[start++] - '0';
		}
		if (s[start] == VT)
			start--;
		start++;
	}
}

void	ft_find_precision(t_var *vari, const char *s, int start)
{
	while (s[start] != vari->type && vari->flag_preci == -1)
	{
		if (s[start] == '.')
		{
			start++;
			if (s[start] == '*')
			{
				VP = (int)va_arg(vari->args, int);
				if (VP < 0)
					VP = -1;
				break ;
			}
			if (s[start] == '-')
				break ;
			vari->flag_preci = 0;
			while (ft_isdigit(s[start]) == 1)
			{
				vari->flag_preci = vari->flag_preci * 10 + s[start] - '0';
				start++;
			}
		}
		else
			start++;
	}
}

void	ft_find_flaglength(t_var *vari, const char *s, int start)
{
	while (s[start] != vari->type && vari->flag_long == '0')
	{
		if (s[start] == 'j' || s[start] == 'z')
			vari->flag_long = s[start];
		else if (s[start] == 'h' && s[start + 1] == 'h')
			vari->flag_long = 'H';
		else if (s[start] == 'l' && s[start + 1] == 'l')
			vari->flag_long = 'L';
		else if (s[start] == 'l')
			vari->flag_long = s[start];
		else if (s[start] == 'h')
			vari->flag_long = s[start];
		start++;
	}
}

void	ft_find(t_var *vari, const char *s, int start)
{
	ft_find_attribut(vari, s, start);
	ft_find_field(vari, s, start);
	ft_find_precision(vari, s, start);
	ft_find_flaglength(vari, s, start);
}
