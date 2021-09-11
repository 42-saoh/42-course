/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:35:41 by saoh              #+#    #+#             */
/*   Updated: 2021/09/11 16:17:05 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	print_state(long time, t_ph *ph, char *s)
{
	pthread_mutex_lock(&ph->p_d->msg_mutex);
	if (time > 100000000000)
		return ;
	printf("%ldms %d %s\n", time, ph->p_n, s);
	pthread_mutex_unlock(&ph->p_d->msg_mutex);
}
