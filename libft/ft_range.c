/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:23:56 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/16 21:36:38 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		i;
	int		*tab;

	i = 0;
	if (min >= max)
		return (NULL);
	if (!(tab = (int*)malloc(sizeof(*tab) * (max - min))))
		return (NULL);
	while (i != (max - min))
	{
		tab[i] = (min + i);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
