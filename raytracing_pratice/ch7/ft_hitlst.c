#include "ch7.h"

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

int				hitlst_hit(t_list *lst, t_hitlst_info *info)
{
	int			hit_anything;
	t_hittable	*hittable;

	hit_anything = 0;
	while (lst && lst->content)
	{
		hittable = (t_hittable *)(lst->content);
		info->mat = hittable->mat;
		if ((*(hittable->hit))(hittable->obj, info->ray, info, info->rec))
		{
			hit_anything = 1;
			info->t_max = info->rec->t;
		}
		lst = lst->next;
	}
	return (hit_anything);
}
