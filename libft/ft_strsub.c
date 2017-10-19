/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:44:58 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/22 19:22:24 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	size_s;
	char	*dest;
	size_t	i;

	i = 0;
	size_s = len;
	dest = NULL;
	if (!(s))
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(*dest) * size_s + 1)))
		return (NULL);
	while (i < size_s && s[start] != '\0')
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
