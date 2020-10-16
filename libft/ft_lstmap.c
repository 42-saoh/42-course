/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:49:12 by saoh              #+#    #+#             */
/*   Updated: 2020/10/16 16:19:07 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	void	*a;
	int		len;

	curr = lst;
	while (curr != NULL)
	{
		a = f(curr->content);
		del(curr->content);
		curr->content = malloc(sizeof(a) + 1);
		len = ft_strlen(a);
		ft_strlcpy(curr->content, a, len + 1);
		free(a);
		curr = curr->next;
	}
	return (lst);
}
