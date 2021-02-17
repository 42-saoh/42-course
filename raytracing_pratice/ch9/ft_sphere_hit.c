#include "ch9.h"

int				check_sphere_hitrange(void *s, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec)
{
	int			is_big_t;
	double		t;

	is_big_t = 0;
	while (is_big_t < 2)
	{
		t = (-info->half_b + info->root_d * (is_big_t ? (1) : (-1))) / info->a;
		if (info->t_min < t && t < info->t_max)
		{
			if (rec->p)
				reset_hit_record(rec);
			rec->t = t;
			rec->p = ray_at(r, t);
			rec->normal = vec_sub(rec->p, ((t_sphere *)s)->center);
			vec_div_const_apply(rec->normal, ((t_sphere *)s)->radius);
			hit_set_normal(rec, r);
			rec->mat = info->mat;
			return (1);
		}
		is_big_t++;
	}
	return (0);
}

int				sphere_hit(void *s, t_ray *r, t_hitlst_info *info,
		t_hit_record *rec)
{
	t_vec		*oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;

	oc = vec_sub(r->orig, ((t_sphere *)s)->center);
	a = vec_dot(r->dir, r->dir);
	half_b = vec_dot(oc, r->dir);
	c = vec_dot(oc, oc) - pow(((t_sphere *)s)->radius, 2);
	discriminant = pow(half_b, 2) - (a * c);
	free(oc);
	if (discriminant < 0)
		return (0);
	info->a = a;
	info->half_b = half_b;
	info->root_d = sqrt(discriminant);
	return (check_sphere_hitrange(s, r, info, rec));
}
