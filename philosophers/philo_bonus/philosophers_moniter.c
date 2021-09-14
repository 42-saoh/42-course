/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_moniter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:59:12 by saoh              #+#    #+#             */
/*   Updated: 2021/07/17 15:54:15 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*eat_moniter(void *arg)
{
	t_ph	*ph;
	int		i;

	ph = (t_ph *)arg;
	if (!ph->p_d->n_o_t)
		return (NULL);
	i = 0;
	while (i < ph->p_d->n_o_p)
	{
		sem_wait(ph[i].eat_end);
		i++;
	}
	kill(ph[0].p_pid, SIGKILL);
	return (NULL);
}

void	*philoso_moniter(void *arg)
{
	t_ph	*ph;
	long	c_time;

	ph = (t_ph *)arg;
	c_time = 0;
	while (c_time < ph->eat_time + ph->p_d->t_t_d || ph->eat_flag)
	{
		c_time = get_time();
		usleep(5);
	}
	print_state(c_time - ph->p_d->first_time, ph, "is died");
	exit(0);
}