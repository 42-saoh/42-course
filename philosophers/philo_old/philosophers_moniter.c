/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_moniter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:59:12 by saoh              #+#    #+#             */
/*   Updated: 2021/07/07 14:09:38 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philoso_moniter(void *arg)
{
	t_ph	*ph;
	long	c_time;

	ph = (t_ph *)arg;
	c_time = 0;
	while (c_time <= ph->eat_time + ph->p_d->t_t_d || ph->eat_flag)
	{
		c_time = get_time();
		usleep(5);
	}
	write_state(c_time - ph->first_time, ph, " is died\n", 9);
	pthread_mutex_unlock(&ph->p_d->end_mutex);
	return (NULL);
}
