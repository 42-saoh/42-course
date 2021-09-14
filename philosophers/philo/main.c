/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:28:46 by saoh              #+#    #+#             */
/*   Updated: 2021/09/14 16:19:49 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_free(t_p_data *p_d)
{
	if (p_d->forks)
		free(p_d->forks);
	if (p_d->mutexes)
		free(p_d->mutexes);
	if (p_d->pt)
		free(p_d->pt);
}

static int	print_error(t_p_data *p_d, int i)
{
	if (i == 1)
		printf("Memory allocation error\n");
	else if (i == 2)
		printf("Arguments error\nplz check arguments and retry\n");
	ft_free(p_d);
	return (1);
}

static int	ft_atoi(char *str)
{
	int	i;
	int	result;

	if (str == NULL)
		return (0);
	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}

static int	set_p_data(t_p_data *p_d, char **argv, int argc)
{
	memset(p_d, 0, sizeof(t_p_data));
	p_d->n_o_p = ft_atoi(argv[1]);
	p_d->t_t_d = ft_atoi(argv[2]) * 1000;
	p_d->t_t_e = ft_atoi(argv[3]) * 1000;
	p_d->t_t_s = ft_atoi(argv[4]) * 1000;
	p_d->n_o_t = ft_atoi(argv[5]);
	if (!p_d->n_o_p || !p_d->t_t_d || !p_d->t_t_e || !p_d->t_t_s || argc > 6)
		return (print_error(p_d, 2));
	p_d->mutexes = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * p_d->n_o_p);
	if (!p_d->mutexes)
		return (print_error(p_d, 1));
	p_d->forks = (int *)malloc(sizeof(int) * p_d->n_o_p);
	if (!p_d->forks)
		return (print_error(p_d, 1));
	p_d->pt = (pthread_t *)malloc(sizeof(pthread_t) * p_d->n_o_p);
	if (!p_d->pt)
		return (print_error(p_d, 1));
	return (0);
}

int	main(int argc, char **argv)
{
	t_p_data	p_d;
	t_ph		*ph;
	int			i;

	if (set_p_data(&p_d, argv, argc))
		return (0);
	ph = (t_ph *)malloc(sizeof(t_ph) * p_d.n_o_p);
	if (!ph)
		return (print_error(&p_d, 1));
	memset(ph, 0, sizeof(t_ph));
	i = 0;
	while (i < p_d.n_o_p)
	{
		ph[i].p_n = i;
		ph[i].p_d = &p_d;
		i++;
	}
	philo(ph);
	ft_free(&p_d);
	free(ph);
	return (0);
}
