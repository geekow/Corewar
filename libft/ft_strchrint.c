/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:40:08 by jjaouen           #+#    #+#             */
/*   Updated: 2016/12/13 05:00:08 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchrint(const char *s, int c)
{
	int		i;
	int		size;

	size = ft_strlen(s);
	i = 0;
	while (s[i] != c && i < size)
		i++;
	if (s[i] == c)
		return (i);
	else
		return (-1);
}
