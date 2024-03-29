#include "ch13.h"

t_thread_info		*tinfo_new(t_camera *cam, t_list *lst, int tnum)
{
	t_thread_info	*result;

	result = (t_thread_info *)malloc(sizeof(t_thread_info));
	result->cam = cam;
	result->lst = lst;
	result->tnum = tnum;
	return (result);
}

int					tinfo_get_step(t_thread_info *info)
{
	return (info->cam->data->height / PTHREAD_CNT);
}

int					tinfo_get_y_init_value(t_thread_info *info)
{
	if (info->tnum == PTHREAD_CNT)
		return (info->cam->data->height);
	return (tinfo_get_step(info) * info->tnum);
}
