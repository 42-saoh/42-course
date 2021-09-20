/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:35:41 by saoh              #+#    #+#             */
/*   Updated: 2021/09/20 17:34:44 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 100);
}

void	print_state(long time, t_ph *ph, char *s)
{
	sem_wait(ph->p_d->msg);
	printf("%ldms %d %s\n", time, ph->p_n, s);
	if (ph->die_flag)
		return ;
	sem_post(ph->p_d->msg);
}
