/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hitlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:53:06 by saoh              #+#    #+#             */
/*   Updated: 2021/03/26 14:47:04 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (lst->next != NULL)
		free_hitlst(lst->next);
	if (lst->content != NULL)
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
		if ((*(hittable->hit))(hittable->obj, info->ray, info, info->rec))
		{
			hit_anything = 1;
			info->t_max = info->rec->t;
		}
		lst = lst->next;
	}
	return (hit_anything);
}

int				hitlst_sh_hit(t_list *lst, t_ray *s_ray, t_hitlst_info *info)
{
	t_hittable	*hittable;

	while (lst && lst->content)
	{
		hittable = (t_hittable *)(lst->content);
		if ((*(hittable->s_hit))(hittable->obj, s_ray, info))
		{
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}
