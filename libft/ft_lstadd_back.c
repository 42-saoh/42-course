/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:00:29 by saoh              #+#    #+#             */
/*   Updated: 2020/10/18 18:22:51 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (new == NULL)
		return ;
	curr = *lst;
	if (curr == NULL)
	{
		curr = ft_lstnew(NULL);
		curr->next = new;
		*lst = curr;
	}
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new;
	}
}
