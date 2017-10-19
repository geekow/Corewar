/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 05:04:08 by jjaouen           #+#    #+#             */
/*   Updated: 2016/12/14 05:43:20 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freeif(char const *s1, char const *s2, int f)
{
	if (f == 1)
		free((void *)(s1));
	else if (f == 2)
	{
		free((void *)(s1));
		free((void *)(s2));
	}
}

char	*ft_strjoinf(char const *s1, char const *s2, int f)
{
	int		size;
	char	*dest;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!(s1 && s2))
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2));
	if (!(dest = (char *)malloc(sizeof(*dest) * size + 1)))
		return (NULL);
	while (s1[i])
	{
		dest[i2] = s1[i];
		i++;
		i2++;
	}
	i = 0;
	while (s2[i])
		dest[i2++] = s2[i++];
	dest[i2] = '\0';
	ft_freeif(s1, s2, f);
	return (dest);
}
