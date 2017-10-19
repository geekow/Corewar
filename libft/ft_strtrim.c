/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:49:02 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/15 17:55:56 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;
	char	*str;

	start = 0;
	str = NULL;
	if (!s)
		return (NULL);
	while (s[start] && (s[start] == ' ' || s[start] == '\n' ||
				s[start] == '\t'))
		start++;
	len = (ft_strlen(s)) - 1;
	while (len > start && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	str = ft_strsub(s, start, ((len + 1) - start));
	return (str);
}
