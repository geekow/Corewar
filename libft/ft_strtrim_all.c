/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 21:51:30 by jjaouen           #+#    #+#             */
/*   Updated: 2017/10/05 22:59:18 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int			ft_valid_char(char c)
{
	if (ft_isprint(c) && c != ' ' && c != '\t')
		return (1);
	else
		return (0);
}

int			get_size_trim(char *str)
{
	int		size;
	int		i;
	int		nb_words;

	size = 0;
	i = -1;
	nb_words = 0;
	while (str[++i])
	{
		if (((str[i] == '\t' || str[i] == ' ') && i != 0 &&
			(ft_isalnum(str[i - 1]) || ft_valid_char(str[i - 1])))
				|| ((ft_isalnum(str[i]) || ft_valid_char(str[i]))
					&& str[i + 1] == '\0'))
			nb_words++;
		if (ft_isalnum(str[i]) || ft_valid_char(str[i]))
			size++;
	}
	if (nb_words + size == 0)
		return (0);
	return (nb_words + size - 1);
}

char		*ft_strtrim_all(char *str)
{
	char	*result;
	int		size;
	int		i;
	int		u;

	i = -1;
	u = 0;
	size = get_size_trim(str);
	result = ft_strnew((size_t)size);
	while (str[++i])
	{
		if (ft_isalnum(str[i]) || ft_valid_char(str[i]))
		{
			result[u] = str[i];
			u++;
			if ((str[i + 1] == '\t' || str[i + 1] == ' ') && u != size)
			{
				result[u] = ' ';
				u++;
			}
		}
	}
	return (result);
}
