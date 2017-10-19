/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:35:00 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/16 20:16:33 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		i2;
	int		i3;

	i = 0;
	i3 = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		i2 = i;
		i3 = 0;
		while (big[i2] == little[i3] && (size_t)i2 < len)
		{
			i2++;
			i3++;
			if (little[i3] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
