/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:29:31 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/16 21:48:08 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	long	d;
	long	c;
	long	i;

	i = 0;
	d = 0;
	c = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			c++;
		else if (f(tab[i], tab[i + 1]) > 0)
			d++;
		i++;
	}
	if ((c > 0 && d == 0) || (c == 0 && d > 0))
		return (1);
	else if (c == 0 && d == 0)
		return (1);
	else
		return (0);
}
