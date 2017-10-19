/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 03:28:12 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/10 07:08:49 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_apply_modif(t_var *vari, char **dst, char **char_arg)
{
	if (VH != 0 || VS != 0 || VPL != 0 || VM != 0 || VF != -1 ||
			VP != -1 || VZ != 0)
	{
		apply_surcharge(vari);
		get_size_arg(vari, dst, char_arg);
		place_arg_and_fill(vari, dst, char_arg);
	}
	else
	{
		*dst = ft_memallocexit(ft_strlen(*char_arg) + 1);
		ft_strcpy(*dst, *char_arg);
	}
}

void		ddi_neg(t_var *vari, char **dst, char **char_arg)
{
	int		i;

	i = 1;
	if (VP == ft_strlen(*char_arg))
		((*dst)[ft_strchrint(*dst, '-')]) = '0';
	((*dst)[ft_strchrint(*dst, '-') - i]) = '0';
	if (VP != ft_strlen(*char_arg))
		((*dst)[ft_strchrint(*dst, '-')]) = '0';
	if (ft_strchrint(*dst, '0') == 0)
	{
		((*dst)[0]) = '-';
		((*dst)[1]) = '0';
	}
	else
	{
		((*dst)[ft_strchrint(*dst, '0') - i]) = '-';
		if (VP != VF && VF != -1)
			ft_memset(*dst, ' ', ft_strchrint(*dst, '-'));
		else
			((*dst)[ft_strchrint(*dst, '0')]) = '-';
	}
}

void		preci_zero(t_var *vari, char **dst, int i)
{
	if (VF == -1)
	{
		if (VPL == 1 && VAP == 1)
			((*dst)[i - 1]) = '+';
		((*dst)[i]) = '\0';
	}
	else if (VF != -1 && VPL == 0)
		((*dst)[i]) = ' ';
	else if (VAP == 1 && VPL == 1)
		((*dst)[i]) = '+';
}

int			ft_initialize(t_var *vari)
{
	if (!(vari->dst = (char*)malloc(sizeof(char) * 1000)))
		return (-1);
	vari->dst[0] = '\0';
	vari->added_char = 0;
	vari->buff_size = 1000;
	vari->error = '0';
	vari->backz = 0;
	return (1);
}

int			ft_addchar(t_var *vari, char c)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	vari->added_char++;
	if (vari->added_char == (vari->buff_size - 4))
	{
		if (!(tmp = (char*)malloc(sizeof(char) * vari->buff_size)))
			return (-1);
		vari->buff_size += 1000;
		ft_strcpy(tmp, vari->dst);
		free(vari->dst);
		if (!(vari->dst = (char*)malloc(sizeof(char) * vari->buff_size)))
			return (-1);
		ft_strcpy(vari->dst, tmp);
		free(tmp);
	}
	while (i != (vari->added_char - 1))
		i++;
	vari->dst[i] = c;
	vari->dst[i + 1] = '\0';
	return (1);
}
