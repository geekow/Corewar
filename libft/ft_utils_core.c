/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 06:48:49 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/10 06:54:10 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_arg_modified(t_var *vari, char **dst)
{
	int i;

	i = -1;
	if (vari->backz != 0 && *dst != NULL)
	{
		while (vari->backz != 0)
		{
			if (((*dst)[++i]) == '\0')
				vari->backz--;
			ft_addchar(vari, ((*dst)[i]));
		}
	}
	else if (*dst != NULL)
		while (((*dst)[++i]) != '\0')
			ft_addchar(vari, ((*dst)[i]));
	if (*dst != NULL)
		ft_strdel(dst);
}
