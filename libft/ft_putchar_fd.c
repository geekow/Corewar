/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:59:13 by jjaouen           #+#    #+#             */
/*   Updated: 2017/01/10 04:03:25 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(int c, int fd)
{
	int		cu;
	char	str[4];
	int		i;
	int		size;

	cu = c;
	i = 0;
	if (cu > 127 && (size = 2))
	{
		if (cu > 2047 && (size = 3))
		{
			if (cu > 65535 && (++size) && (str[i++] = ((cu >> 18) & 7) | 240))
				str[i++] = ((cu >> 12) & 63) | 128;
			else
				str[i++] = ((cu >> 12) & 15) | 224;
			str[i++] = ((cu >> 6) & 63) | 128;
		}
		else
			str[i++] = ((cu >> 6) & 31) | 192;
		str[i++] = (cu & 63) | 128;
		write(fd, &str, size);
	}
	else
		write(fd, &c, 1);
}
