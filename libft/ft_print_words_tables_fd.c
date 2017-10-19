/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables_fd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 07:55:47 by jjaouen           #+#    #+#             */
/*   Updated: 2017/02/13 07:57:20 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_tables_fd(int fd, char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}
