#include "ft_libftprintf.h"
#include <stdio.h>

static void		ft_until_persent_str(t_lst *lst)
{
	char			*str;

	if (lst->chrf == lst->f)
	{
		lst->f++;
		return ;
	}
	if (!(str = ft_substr(lst->f, 0, lst->chrf - lst->f)))
	{
		lst->result = -1;
		return ;
	}
	ft_lstadd_back(&lst->list, ft_lstnew(str));
	lst->f = lst->chrf + 1;
	return ;
}

void			ft_print(t_lst *lst)
{
	t_list		*curr;
	int			len;

	curr = lst->list;
	len = 0;
	while(curr != NULL)
	{
		len = ft_strilen(curr->content);
		write(1, curr->content, len);
		lst->result = lst->result + len;
		curr = curr->next;
	}
}

static void		ft_init_lst(t_lst *lst)

{
	lst->minus = 0;
	lst->result = 0;
	lst->zero = 0;
	lst->nm = 0;
	lst->precision = 0;
	lst->width = 0;
	lst->prewidth = 0;
	lst->len = 0;
}

int main()
{
	t_lst *lst;

	lst = malloc(sizeof(t_lst));
	lst->list = NULL;
	lst->result = 0;
	lst->f = "asdasd%dasdasd";
	while ((lst->chrf = ft_strchr(lst->f, '%')) != NULL)
	{
		ft_until_persent_str(lst);
		ft_init_lst(lst);
		ft_sort_symbol(lst);
		ft_print(lst);
	}
}
