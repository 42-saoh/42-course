/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_vec.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:48:28 by saoh              #+#    #+#             */
/*   Updated: 2021/02/21 21:48:30 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_VEC_H
# define MINIRT_VEC_H
# include "minirt.h"

t_vec					*vec_create(double x, double y, double z);
t_vec					*vec_mul_const_apply(t_vec *vec, double val);
t_vec					*vec_div_const_apply(t_vec *vec, double val);
t_vec					*vec_add(t_vec *vec1, t_vec *vec2);
t_vec					*vec_sub(t_vec *vec1, t_vec *vec2);
t_vec					*vec_add_apply(t_vec *vec1, t_vec *vec2);
t_vec					*vec_sub_apply(t_vec *vec1, t_vec *vec2);
t_vec					*vec_unit_apply(t_vec *vec);
t_vec					*vec_mul_const(t_vec *vec1, double val);
t_vec					*vec_div_const(t_vec *vec1, double val);
double					vec_length_squared(t_vec *vec);
double					vec_length(t_vec *vec);
double					vec_dot(t_vec *vec1, t_vec *vec2);
t_vec					*vec_unit(t_vec *vec);
t_vec					*vec_dup(t_vec *ori);
t_vec					*vec_random_unit(void);
t_vec					*vec_random_in_hemisphere(t_vec *normal);
t_vec					*vec_mul_each_apply(t_vec *vec1, t_vec *vec2);
t_vec					*vec_reflect(t_vec *v, t_vec *n);
t_vec					*vec_random_in_unit_sphere(void);
t_vec					*vec_random_range(double min, double max);
t_vec					*vec_cross(t_vec *vec1, t_vec *vec2);
t_vec					*vec_cross_apply(t_vec *vec1, t_vec *vec2);
int						vec_is_parallel(t_vec *vec1, t_vec *vec2);

#endif
