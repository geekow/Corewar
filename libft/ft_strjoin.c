/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:19:37 by jjaouen           #+#    #+#             */
/*   Updated: 2016/12/14 02:56:08 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (dest);
}
