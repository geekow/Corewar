/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmaj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:02:56 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/20 17:02:59 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	what_is(char c)
{
	if ('0' <= c && c <= '9')
		return (3);
	else if ('a' <= c && c <= 'z')
		return (2);
	else if ('A' <= c && c <= 'Z')
		return (1);
	else
		return (0);
}

char		*ft_strmaj(char *str)
{
	int		i;
	int		i2;

	i = 0;
	while (str[i])
	{
		i2 = what_is(str[i]);
		if (i2 == 2)
		{
			if (!what_is(str[i - 1]) && what_is(str[i + 1]))
				str[i] -= 32;
		}
		if (i2 == 1)
			if (what_is(str[i - 1]))
				str[i] += 32;
		i++;
	}
	return (str);
}
