/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:20:18 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/09 21:50:27 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && n != 0)
	{
		if (*((unsigned char*)s) == (unsigned char)c)
			return ((void *)s);
		s++;
		i++;
	}
	return (NULL);
}
