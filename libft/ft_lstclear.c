/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:24:56 by saoh              #+#    #+#             */
/*   Updated: 2020/10/18 19:59:11 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *curr;

	if (*lst == NULL)
		return ;
	while (*lst != NULL)
	{
		curr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = curr;
	}
}
