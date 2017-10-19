/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:47:52 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/16 21:13:02 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(*dest) * size + 1)))
		return (NULL);
	while (i <= size)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
