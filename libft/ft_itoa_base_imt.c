/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_imt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 21:28:04 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/09 06:52:01 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(intmax_t value, int base)
{
	size_t		i;
	intmax_t	tmp;

	tmp = value;
	i = 0;
	while (tmp != 0)
	{
		tmp /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base_imt(intmax_t value, int base)
{
	char		*dst;
	char		basehexa[17];
	int			i;
	size_t		size;

	i = 0;
	dst = NULL;
	ft_strcpy(basehexa, "0123456789abcdef");
	size = get_size(value, base);
	if (value < 0 && (value *= -1) && base == 10 && (dst = ft_memalloc(++size)))
		dst[0] = '-';
	if (base > 16 || base < 2 || value == 0)
		return ("0");
	if (dst == NULL)
		dst = ft_memalloc(size);
	while (value != 0)
	{
		dst[size - ++i] = basehexa[value % base];
		value /= base;
	}
	dst[size] = '\0';
	return (dst);
}
