/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <saoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:04:22 by saoh              #+#    #+#             */
/*   Updated: 2021/03/25 16:06:12 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_img_data		*create_img_data(int width, int height)
{
	t_img_data	*result;
	int			h;
	int			w;

	result = (t_img_data *)malloc(sizeof(t_img_data));
	result->width = width;
	result->height = height;
	result->img = (int **)malloc(sizeof(int *) * width);
	result->aspect_ratio = width / height;
	w = 0;
	while (w < width)
	{
		result->img[w] = (int *)malloc(sizeof(int) * height);
		h = 0;
		while (h < height)
			result->img[w][h++] = 0;
		w++;
	}
	return (result);
}

t_img_data		*dup_img_data(t_img_data *img)
{
	t_img_data	*result;
	int			h;
	int			w;

	result = (t_img_data *)malloc(sizeof(t_img_data));
	result->width = img->width;
	result->height = img->height;
	result->img = (int **)malloc(sizeof(int *) * img->width);
	result->aspect_ratio = img->aspect_ratio;
	w = 0;
	while (w < img->width)
	{
		result->img[w] = (int *)malloc(sizeof(int) * img->height);
		h = 0;
		while (h < img->height)
			result->img[w][h++] = 0;
		w++;
	}
	return (result);
}

void			free_img_data(t_img_data *data)
{
	int			w;

	w = 0;
	while (w < data->width)
	{
		free(data->img[w]);
		w++;
	}
	free(data->img);
	free(data);
}
