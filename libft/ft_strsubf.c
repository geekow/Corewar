/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 05:19:02 by jjaouen           #+#    #+#             */
/*   Updated: 2016/12/14 05:21:31 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubf(char const *s, unsigned int start, size_t len)
{
	size_t	size_s;
	char	*dest;
	size_t	i;

	i = 0;
	size_s = len;
	if (!(s))
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(*dest) * size_s + 1)))
		return (NULL);
	while (i < size_s)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	free((void *)(s));
	return (dest);
}
