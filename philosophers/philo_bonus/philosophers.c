/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:16:22 by saoh              #+#    #+#             */
/*   Updated: 2021/09/20 14:06:13 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo(t_ph *ph)
{
	int			i;

	i = 0;
	ph->p_d->p_moniter = fork();
	if (ph->p_d->p_moniter == 0)
	{
		eat_moniter(ph);
		exit(0);
	}
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
