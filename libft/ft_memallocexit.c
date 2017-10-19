/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memallocexit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 07:05:39 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/10 07:06:59 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memallocexit(size_t size)
{
	void	*dest;

	dest = NULL;
	if (!(dest = malloc(size)))
		exit(EXIT_FAILURE);
	ft_bzero(dest, size);
	return (dest);
}
