/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 08:06:50 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/06 08:15:40 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_replace_char(char *src, char modif, char replace)
{
	int		i;

	i = -1;
	while (src[++i])
		if (src[i] == modif)
			src[i] = replace;
	return (src);
}
