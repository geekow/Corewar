/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flagmin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:36:34 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/09 06:17:23 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_apply_attributmin(t_var *vari, char **dst, int s_arg)
{
	if (VH == 1 || VH == 2)
	{
		if (VT == 'x' || VT == 'X')
		{
			ft_move_char_right(*dst, '0', 2);
			((*dst)[1]) = (VT == 'x') ? 'x' : 'X';
		}
		if ((VT == 'o' || VT == 'O') && s_arg > VP)
			ft_move_char_right(*dst, '0', 1);
	}
	if (VPL == 1 && VAP == 1)
		ft_move_char_right(*dst, '+', 1);
	if ((VT == 'd' || VT == 'i') && VAP == 0 && ft_strchrint(*dst, '-') != 0)
	{
		((*dst)[ft_strchrint(*dst, '-')]) = '0';
		ft_move_char_right(*dst, '-', 1);
	}
	if (VS == 1 && VT != 'u' && VT != 'U' && VAP == 1)
		ft_move_char_right(*dst, ' ', 1);
}

void		ft_apply_flagmin(t_var *vari, char **dst, char **char_arg)
{
	int		s_arg;
	int		i;

	s_arg = ft_strlen(*char_arg);
	i = -1;
	while (((*char_arg)[++i]))
		((*dst)[i]) = ((*char_arg)[i]);
	if (VP != -1 && VP > s_arg)
		ft_move_char_right(*dst, '0', (VP - s_arg));
	ft_apply_attributmin(vari, dst, s_arg);
	if (ft_atoi_base(*char_arg, 10) == 0 && VP == 0)
		preci_zero(vari, dst, ft_strchrint(*dst, '0'));
}
