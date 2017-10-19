/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 00:21:02 by jjaouen           #+#    #+#             */
/*   Updated: 2016/12/13 04:31:52 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	if (new && *alst)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*alst = new;
}
