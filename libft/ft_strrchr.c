/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:28:35 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/15 18:55:03 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		size;
	int		tmp;
	char	*a;

	a = (char *)s;
	size = ft_strlen(s);
	i = 0;
	tmp = -1;
	if (!(s))
		return (NULL);
	while (i < size)
	{
		if (s[i] == c)
			tmp = i;
		i++;
	}
	if (tmp != -1)
		return ((char *)s + tmp);
	else if (c == 0)
		return (a + i);
	return (NULL);
}
