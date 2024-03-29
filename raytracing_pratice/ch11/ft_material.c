#include "ch10.h"

void					free_material(t_material *mat)
{
	free(mat->color);
	free(mat);
}

t_material				*material_new(int mat_type, t_vec *color)
{
	t_material			*result;

	result = (t_material *)malloc(sizeof(t_material));
	result->color = color;
	result->mat_type = mat_type;
	return (result);
}

t_material				*material_dup(t_material *mat)
{
	t_material			*result;

	result = (t_material *)malloc(sizeof(t_material));
	result->color = vec_dup(mat->color);
	result->mat_type = mat->mat_type;
	result->scatter = mat->scatter;
	if (mat->mat_type == MAT_METAL)
		result->fuzz = mat->fuzz;
	return (result);
}

t_material_info			*material_info_new(void)
{
	t_material_info		*result;

	result = (t_material_info *)malloc(sizeof(t_material_info));
	result->attenuation = NULL;
	result->scattered = NULL;
	return (result);
}

void					free_material_info(t_material_info *info,
		int is_ori_free, int is_scattered_free)
{
	if (info->attenuation)
		free(info->attenuation);
	if (info->scattered && is_scattered_free)
		ray_free(info->scattered, 1);
	if (is_ori_free)
		free(info);
}
