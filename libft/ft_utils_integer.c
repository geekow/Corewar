/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:43:14 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/09 03:07:04 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_without_min(t_var *vari, char **dst, char **char_arg)
{
	if ((VZ == 1 || VP > ft_strlen(*char_arg)) && VM == 0)
	{
		ft_memset(*dst, '0', (ft_strlen(*dst) - ft_strlen(*char_arg)));
		if (VF >= VP && VZ == 0 && VP != -1)
			ft_memset(*dst, ' ', (VF - VP));
	}
	else if (VS == 1 && VM == 0)
		ft_memset(*dst, ' ', (ft_strlen(*dst) - ft_strlen(*char_arg)));
}

void	ft_convert_p(t_var *vari, char **dst, char **char_arg, int i)
{
	int		j;

	j = ft_strlen(*char_arg);
	if (VF != -1)
		i = VF - (ft_strlen(*char_arg) + 2);
	if (VZ == 1 && VM == 0)
		i = 0;
	else if (VF < j || (VZ == 1 && VM == 0))
		i = 0;
	((*dst)[i]) = '0';
	((*dst)[i + 1]) = (VT == 'x') ? 'x' : 'X';
	if (VP != 0)
		((*dst)[i + 2]) = '0';
	else
		((*dst)[i + 2]) = '\0';
}

void	ft_apply_vsvzvpzero(t_var *vari, char **dst, char **char_arg, int i)
{
	int		size;

	size = ft_strlen(*char_arg);
	if (VS == 1 && VAP == 1 && VF > size && VP == -1)
		((*dst)[i]) = ' ';
	if (VZ == 1 && VAP != 0)
		ft_memset(*dst, '0', i);
	if (VP == 0 && ft_atoi_imt(*char_arg) == 0 && VH != 2)
		preci_zero(vari, dst, i);
}

int		ft_vh_attribut(t_var *vari, char **dst, char **char_arg, int i)
{
	int		j;

	j = ft_strlen(*char_arg);
	if (((VT == 'x' || VT == 'X') && (ft_atoi_imt(*char_arg) != 0)) ||
		(VH == 2 && VP == -1 && VF == -1 && ft_atoi_base(*char_arg, 16) < 0))
	{
		if (VF < j || (VH == 2 && VF > VP && VP > j))
			i = 0;
		else if (i > 2)
			i = i - 2;
		((*dst)[i]) = '0';
		((*dst)[i + 1]) = (VT == 'x') ? 'x' : 'X';
	}
	else if (VH == 2 && ft_atoi_imt(*char_arg) == 0)
		ft_convert_p(vari, dst, char_arg, i);
	else if (VH == 2)
		((*dst)[1]) = 'x';
	else if ((VT == 'o' || VT == 'O') && j > VP)
	{
		if ((VF > j && VZ == 0) || (VF == -1 && VP < j))
			i--;
		((*dst)[i]) = '0';
	}
	return (i);
}
