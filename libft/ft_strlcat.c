/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:58:57 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/09 14:10:36 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	d_size;
	size_t	s_size;

	i = 0;
	d_size = ft_strlen(dst);
	s_size = ft_strlen(src);
	if (d_size > size)
		return (size + s_size);
	while ((i + d_size) < (size - 1) && src[i])
	{
		dst[d_size + i] = src[i];
		i++;
	}
	dst[d_size + i] = '\0';
	return (d_size + s_size);
}
