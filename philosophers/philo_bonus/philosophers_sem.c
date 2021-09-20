/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_sem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:22:45 by saoh              #+#    #+#             */
/*   Updated: 2021/09/20 17:31:37 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sema_exit(t_ph *ph, t_p_data *p_d, int num)
{
	char	*name;
	int		i;

	sem_close(p_d->forks);
	sem_unlink("forks");
	sem_close(p_d->end);
	sem_unlink("end");
	sem_close(p_d->msg);
	sem_unlink("msg");
	if (ph)
	{
		i = 0;
		while (i < num)
		{
			name = get_name(i);
			sem_close(ph[i].eat_end);
			sem_unlink(name);
			free(name);
			name = 0;
			i++;
		}
	}
}

char	*get_name(int n)
{
	char	*result;

	result = (char *)malloc(sizeof(char) + 5);
	result[0] = 'e';
	result[1] = n / 100 + '0';
	result[2] = ((n % 100) / 10) + '0';
	result[3] = (n % 10) + '0';
	result[4] = 0;
	return (result);
}

void	sema_error(void)
{
	char	*name;
	int		i;

	sem_unlink("forks");
	sem_unlink("end");
	sem_unlink("msg");
	i = 0;
	while (i < 201)
	{
		name = get_name(i);
		sem_unlink(name);
		free(name);
		name = 0;
		i++;
	}
}
