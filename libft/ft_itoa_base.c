/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:03:04 by jjaouen           #+#    #+#             */
/*   Updated: 2017/01/20 21:27:55 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int value, int base)
{
	size_t		i;
	int			tmp;

	tmp = value;
	i = 0;
	while (tmp != 0)
	{
		tmp /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int value, int base)
{
	char			*dst;
	char			basehexa[17];
	int				i;
	size_t			size;

	i = 0;
	dst = NULL;
	ft_strcpy(basehexa, "0123456789abcdef");
	size = get_size(value, base);
	if (base > 16 || base < 2 || value == 0)
		return ("0");
	if (value < 0 && (value *= -1) && base == 10 && (dst = ft_memalloc(++size)))
		dst[0] = '-';
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
