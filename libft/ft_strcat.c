/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:40:02 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/09 13:56:26 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, char *src)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (dst[size])
		size++;
	while (src[i])
	{
		dst[size] = src[i];
		i++;
		size++;
	}
	dst[size] = '\0';
	return (dst);
}
