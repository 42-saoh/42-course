/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:35:41 by saoh              #+#    #+#             */
/*   Updated: 2021/07/06 18:10:18 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long				get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

static void			ft_write_itoa(int num)
{
	char			str[13];
	int				i;

	if (num == 0)
		str[0] = '0';
	i = 0;
	while(num > 0)
	{
		str[i++] = (num % 10) + '0';
		num = num / 10;
	}
	if (i > 0)
		i--;
	while (i >= 0)
		write(1, &str[i--], 1);
}

void				write_state(int time, t_ph *ph, char *s, int len)
{
	pthread_mutex_lock(&ph->p_d->msg_mutex);
	ft_write_itoa(time);
	write(1, "ms ", 3);
	ft_write_itoa(ph->p_n);
	write(1, s, len);
	pthread_mutex_unlock(&ph->p_d->msg_mutex);
}
