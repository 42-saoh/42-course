/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_moniter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:59:12 by saoh              #+#    #+#             */
/*   Updated: 2021/09/20 16:35:49 by saoh             ###   ########.fr       */
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
		if (ph->p_d->die_flag)
			return (NULL);
		if (cnt == i)
			break ;
	}
	ph->p_d->die_flag = 1;
	return (NULL);
}

void	*philoso_moniter(void *arg)
{
	t_ph	*ph;
	t_ph	*ph_all;
	long	c_time;
	int		i;

	ph_all = (t_ph *)arg;
	while (1)
	{
		i = 0;
		while (i < ph_all->p_d->n_o_p)
		{
			ph = &ph_all[i];
			c_time = get_time();
			if (c_time > ph->eat_time + ph->p_d->t_t_d && !ph->eat_flag)
				break ;
			i++;
		}
	}
	ph->p_d->die_flag = 1;
	printf("%ldms %d is died\n", c_time - ph->p_d->first_time, ph->p_n);
	if (ph->p_d->n_o_p == 1)
		pthread_mutex_unlock(&ph->p_d->mutexes[0]);
	return (NULL);
}
