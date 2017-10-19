/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:28:30 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/07 20:05:46 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		i2;
	int		i3;

	i = 0;
	i3 = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		i2 = i;
		i3 = 0;
		while (big[i2] == little[i3])
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
