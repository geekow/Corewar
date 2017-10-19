/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_attribut_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:27:09 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/10 07:10:39 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_apply_attribut(t_var *vari, char **dst, char **char_arg)
{
	int		i;
	int		j;

	i = -1;
	j = ft_strlen(*char_arg);
	while (ft_isalnum(((*dst)[++i])) == 0)
		;
	if (VH == 1 || VH == 2)
		i = ft_vh_attribut(vari, dst, char_arg, i);
	if (VPL == 1)
	{
		if ((VP == -1 && VF == -1) || (VAP == 1 && VF > j && VT == 'i'))
			((*dst)[--i]) = '+';
		else if ((j == (VP - 1) && i--) || 1)
			((*dst)[i]) = '+';
	}
	if (((VT == 'i' || VT == 'd') && VAP == 0 && VF > j
			&& VZ == 1) || (VF > j && VAP == 0 && VP == j &&
				(VT == 'd' || VT == 'i')))
	{
		((*dst)[ft_strchrint(*dst, '-')]) = '0';
		((*dst)[0]) = '-';
	}
	ft_apply_vsvzvpzero(vari, dst, char_arg, i);
}

void	place_arg_and_fill(t_var *vari, char **dst, char **char_arg)
{
	int	size;
	int	i;

	size = ft_strlen(*dst);
	i = -1;
	if (VM == 0)
	{
		while (((*char_arg)[++i]) != '\0' && VM == 0)
			((*dst)[++size - (ft_strlen(*char_arg)) - 1]) = ((*char_arg)[i]);
		ft_flag_without_min(vari, dst, char_arg);
		if (VP != -1 && (VT == 'i' || VT == 'd' || VT == 'D') &&
		VAP == 0 && VM == 0 && VP > ft_strlen(*char_arg))
			ddi_neg(vari, dst, char_arg);
		ft_apply_attribut(vari, dst, char_arg);
	}
	else if (VM == 1)
		ft_apply_flagmin(vari, dst, char_arg);
	i = -1;
	while (((*dst)[++i]) != '\0')
		if (((*dst)[i]) == '.')
			((*dst)[i]) = ' ';
}

void	apply_surcharge(t_var *vari)
{
	if (VT == 'd' || VT == 'D' || VT == 'i' || VT == 'X' || VT == 'x'
			|| VT == 'o' || VT == 'O' || VT == 'u' || VT == 'U')
	{
		if (VH == 1 && (VT == 'd' || VT == 'D' || VT == 'i'))
			VH = 0;
		if (VP != -1 && VZ != 0)
			VZ = 0;
		if ((VT == 'x' || VT == 'X' || VT == 'o' || VT == 'O' || VT == 'u' ||
					VT == 'U') && VPL == 1)
			VPL = 0;
	}
	if ((VT == 'd' || VT == 'D' || VT == 'i') && VPL == 1 && VAP == 0)
		VPL = 0;
	if (VT == 'd' || VT == 'D' || VT == 'i')
		if (VS != 0 && VPL != 0)
			VS = 0;
	if (VM != 0 && VZ != 0)
		VZ = 0;
	if (VP != -1 && VF != -1)
		if (VP >= VF)
			VF = -1;
}

void	get_size_arg_two(t_var *vari, char **char_arg, int size, char **dst)
{
	if (VF < VP && (VT == 'd' || VT == 'D') && VAP == 0 &&
			ft_strlen(*char_arg) < size && VP > ft_strlen(*char_arg))
		size++;
	if ((VT == 'O' || VT == 'o') && VP < size && VH == 1 && VF < size &&
			ft_atoi_imt(*char_arg) != 0)
		size++;
	if (VP > VF && (VT == 'i') && VAP == 0 && VM == 0)
		size++;
	if (VH == 2 && VF > VP && VP > ft_strlen(*char_arg))
		size++;
	if ((*dst = ft_memallocexit(size + 1)) == NULL)
		exit(1);
	*dst = ft_memset(*dst, '.', size);
	((*dst)[size]) = '\0';
}

void	get_size_arg(t_var *vari, char **dst, char **char_arg)
{
	int		size;

	size = ft_strlen(*char_arg);
	size = (size < VP) ? VP : size;
	if (VF > size)
	{
		if (VH == 2 && size == (VF - 1))
			size = size + 2;
		else
			size = VF;
	}
	else if ((VT == 'x' || VT == 'X' || VT == 'o' || VT == 'O') && VH != 0)
	{
		if (((VT == 'x' || VT == 'X') && (size != 1 &&
						((*char_arg)[0]) != '0')) || (VH == 2))
			size = size + 2;
		else if ((VT == 'o' || VT == 'O') && VP > VF && VP > size)
			size = size + 1;
		if (VM == 1 && ft_strlen(*char_arg) == 1 && VF != -1 && VH == 2)
			size++;
	}
	else if (VF <= size && (VT == 'd' || VT == 'D' || VT == 'i') && VAP == 1)
		if (VS != 0 || VPL != 0)
			size = size + 1;
	get_size_arg_two(vari, char_arg, size, dst);
}
