#include "ch6.h"

t_list			*hitlst_new(void)
{
	t_list		*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	new_lst->content = NULL;
	new_lst->next = NULL;
	return (new_lst);
}

void			hitlst_add(t_list *lst, void *obj, int obj_type)
{
	if (lst->content)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = hitlst_new();
		lst = lst->next;
	}
	lst->content = hittable_create(obj, obj_type);
}

void			free_hitlst(t_list *lst)
{
	if (lst->next)
		free_hitlst(lst->next);
	free_hittable(lst->content);
	free(lst);
}
