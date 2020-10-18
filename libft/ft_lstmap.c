/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:49:12 by saoh              #+#    #+#             */
/*   Updated: 2020/10/18 21:34:57 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*s_lst;
	t_list	*temp;
	t_list	*curr;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	temp = lst;
	s_lst = ft_lstnew(f(lst->content));
	curr = lst->next;
	while (curr != NULL)
	{
		s_lst->next = ft_lstnew(f(curr->content));
		s_lst = s_lst->next;
		curr = curr->next;
	}
	ft_lstclear(&temp, del);
	return (s_lst);
}
