/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uimt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 21:30:12 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/09 06:52:25 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(uintmax_t value, int base)
{
	size_t		i;
	uintmax_t	tmp;

	tmp = value;
	i = 0;
	while (tmp != 0)
	{
		tmp /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base_uimt(uintmax_t value, int base)
{
	char		*dst;
	char		basehexa[17];
	int			i;
	size_t		size;

	i = 0;
	dst = NULL;
	ft_strcpy(basehexa, "0123456789abcdef");
	size = get_size(value, base);
	if (base > 16 || base < 2 || value == 0)
		return (ft_strdup("0"));
	dst = ft_memalloc(size + 1);
	while (value != 0)
	{
		dst[size - ++i] = basehexa[value % base];
		value /= base;
	}
	dst[size] = '\0';
	return (dst);
}
