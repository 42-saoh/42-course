/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:16:22 by saoh              #+#    #+#             */
/*   Updated: 2021/09/20 13:41:29 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo(t_ph *ph)
{
	int			i;
	pthread_t	t;

	i = 0;
	pthread_create(&t, NULL, eat_moniter, (void *)ph);
	pthread_detach(t);
	ph[0].p_d->first_time = get_time();
	while (i < ph[0].p_d->n_o_p)
	{
		ph[i].p_pid = fork();
		if (ph[i].p_pid == 0)
		{
			each_philo(&ph[i]);
			exit(0);
		}
		usleep(50);
		i++;
	}
}
