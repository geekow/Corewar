/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:25:12 by jjaouen           #+#    #+#             */
/*   Updated: 2016/11/16 19:53:21 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*newlst;
	t_list	*cpyf;

	tmp = NULL;
	newlst = NULL;
	if (lst == NULL || (*f) == NULL)
		return (NULL);
	cpyf = f(lst);
	if (!(newlst = ft_lstnew(cpyf->content, cpyf->content_size)))
		return (NULL);
	tmp = newlst;
	lst = lst->next;
	while (lst)
	{
		cpyf = f(lst);
		if (!(newlst->next = ft_lstnew(cpyf->content, cpyf->content_size)))
			return (NULL);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (tmp);
}
