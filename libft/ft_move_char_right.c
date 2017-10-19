/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_char_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 06:50:01 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/09 06:51:02 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_move_char_right(char *dst, char c, int n)
{
	int	k;
	int	j;

	k = 0;
	while (k != n)
	{
		j = ft_strlen(dst) + 1;
		if (j == 1)
			j++;
		while (--j != 0)
		{
			if (dst[j] != '\0')
				dst[j] = dst[j - 1];
			if (j == 1)
				dst[j] = dst[j - 1];
			else
				dst[j - 1] = dst[j - 2];
		}
		dst[0] = c;
		k++;
	}
}
