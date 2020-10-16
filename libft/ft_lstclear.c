/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:24:56 by saoh              #+#    #+#             */
/*   Updated: 2020/10/16 15:30:10 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *curr;

	if (lst == 0)
		return ;
	curr = *lst;
	while (curr->next != NULL)
	{
		del(curr->content);
		free(curr);
		curr = curr->next;
	}
	del(curr->content);
	free(curr);
}
