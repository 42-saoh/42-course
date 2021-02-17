#include "ch10.h"

t_hit_record			*hit_record_new(void)
{
	t_hit_record		*result;

	result = (t_hit_record *)malloc(sizeof(t_hit_record));
	result->normal = NULL;
	result->p = NULL;
	return (result);
}

void					reset_hit_record(t_hit_record *rec)
{
	if (rec->normal)
		free(rec->normal);
	if (rec->p)
		free(rec->p);
}

void					free_hit_record(t_hit_record *rec)
{
	reset_hit_record(rec);
	free(rec);
}

void					hit_set_normal(t_hit_record *rec, t_ray *r)
{
	rec->is_front_face = (vec_dot(r->dir, rec->normal) < 0) ? 1 : 0;
	if (rec->is_front_face == 0)
		vec_mul_const_apply(rec->normal, -1);
}
