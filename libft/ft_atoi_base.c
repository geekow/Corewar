/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:01:14 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/09 06:46:02 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_is_valid(const char *str)
{
	int				i;

	i = 0;
	while ((i == 0 && (str[i] == '-' || str[i] == '+')) ||
			(str[i] >= '0' || str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
			|| (str[i] >= 'A' && str[i] <= 'F') || str[i] == '\0')
	{
		if (str[i] == '\0')
			return (i);
		i++;
	}
	return (0);
}

static uintmax_t	ft_find_nb(char *temp, int i, int str_base, uintmax_t nb)
{
	while ((temp[i] != '\0' && (temp[i] >= 0 && temp[i] <= '9')) ||
	((temp[i] >= 'a' && temp[i] <= 'f') || ((temp[i] >= 'A' &&
	temp[i] <= 'F') && temp[i] != '\0')))
	{
		if (temp[i] >= '0' && temp[i] <= '9')
			nb = nb * str_base + temp[i] - '0';
		else if (temp[i] >= 'a' && temp[i] <= 'f')
			nb = nb * str_base + temp[i] - 'a' + 10;
		else if (temp[i] >= 'A' && temp[i] <= 'F')
			nb = nb * str_base + temp[i] - 'A' + 10;
		i++;
	}
	return (nb);
}

int					ft_atoi_base(const char *str, int str_base)
{
	char			*temp;
	uintmax_t		nb;
	int				i;
	int				sign;

	nb = 0;
	sign = 1;
	i = 0;
	if (str_base == 10)
		return (ft_atoi(str));
	temp = ft_memalloc(ft_strlen(str) + 1);
	ft_strcpy(temp, str);
	if (str == NULL || ft_is_valid(temp) == 0 || str_base < 2 || str_base > 16)
		return (0);
	if (temp[i] == '+' || (temp[i] == '-' && (sign = -1) && temp[i] != '\0'))
		i++;
	nb = ft_find_nb(temp, i, str_base, nb);
	free(temp);
	return (nb * sign);
}
