/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:35:26 by jjaouen           #+#    #+#             */
/*   Updated: 2017/03/24 14:47:02 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_stst(const char *s, char c)
{
	int		i;
	int		d;

	d = 0;
	i = 0;
	while (s[d])
	{
		if (d == 0 && s[d] != c)
			i++;
		if (c == s[d] && c != s[d + 1] && s[d + 1])
			i++;
		d++;
	}
	return (i);
}

static int		ft_len(const char *s, char c)
{
	int		i;
	int		e;

	i = 0;
	e = 1;
	while (s[i] && s[i] != c)
	{
		i++;
		e++;
	}
	return (e);
}

static char		**ft_split(char **dst, char const *s, char c)
{
	int		a;
	int		b;
	int		d;

	a = -1;
	b = 0;
	while (s[++a])
	{
		if (s[a + 1] == '\0' && b == 0)
		{
			dst[b] = ft_strdup(s);
			dst[b + 1] = 0;
			return (dst);
		}
		if ((c == s[a] && c != s[a + 1] && s[a + 1]) || (a == 0 && s[a] != c))
		{
			d = 0;
			(a != 0 && s[a] == c) ? (a++) : 1;
			d = ft_len(&s[a + 1], c);
			dst[b++] = ft_strsub(s, a, d);
			a = a + (d - 1);
		}
	}
	dst[b] = 0;
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb;
	char	**tab;

	if (!s)
		return (NULL);
	nb = ft_find_stst(s, c);
	tab = NULL;
	if (ft_find_stst(s, c) == 0)
		nb = 1;
	if (!(tab = malloc(sizeof(char**) * (nb + 1))))
		return (NULL);
	tab = ft_split(tab, s, c);
	return (tab);
}
