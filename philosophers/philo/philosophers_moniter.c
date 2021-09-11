/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_moniter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:59:12 by saoh              #+#    #+#             */
/*   Updated: 2021/09/11 16:15:18 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*eat_moniter(void *arg)
{
	t_ph	*ph;
	int		i;
	int		cnt;

	ph = (t_ph *)arg;
	if (!ph->p_d->n_o_t)
		return (NULL);
	while (1)
	{
		i = 0;
		cnt = 0;
		while (i < ph->p_d->n_o_p)
		{
			if (ph[i].eat_c >= ph[0].p_d->n_o_t)
				cnt++;
			i++;
		}
		if (cnt == i)
			break ;
	}
	ph->p_d->die_flag = 1;
	pthread_mutex_unlock(&ph->p_d->end_mutex);
	return (NULL);
}

void	*philoso_moniter(void *arg)
{
	t_ph	*ph;
	long	c_time;

	ph = (t_ph *)arg;
	c_time = 0;
	while (ph->eat_flag || c_time < ph->eat_time + ph->p_d->t_t_d)
	{
		c_time = get_time();
		usleep(5);
		if (ph->p_d->die_flag)
			return (NULL);
	}
	ph->p_d->die_flag = 1;
	print_state(c_time - ph->p_d->first_time, ph, "is died");
	pthread_mutex_unlock(&ph->p_d->end_mutex);
	return (NULL);
}
