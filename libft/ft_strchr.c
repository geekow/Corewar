/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:56:12 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/07 20:47:56 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		size;

	size = ft_strlen(s);
	i = 0;
	while (s[i] != c && i < size)
		i++;
	if (s[i] == c)
		return ((char *)s + i);
	else
		return (NULL);
}
