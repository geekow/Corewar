/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_imt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 21:16:29 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/09 06:53:58 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		itoa_neg(intmax_t *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_itoa_imt(intmax_t n)
{
	intmax_t	tmp;
	int			len;
	int			neg;
	char		*str;

	tmp = n;
	len = 2;
	neg = 0;
	if (n == (-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
	itoa_neg(&n, &neg);
	while (tmp /= 10)
		len++;
	len += neg;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
