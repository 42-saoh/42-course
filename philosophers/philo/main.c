/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:28:46 by saoh              #+#    #+#             */
/*   Updated: 2021/07/01 18:46:47 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void		free_p_data(t_p_data *p_d)
{
	if (p_d->mutexes != NULL)
		free(p_d->mutexes);
	if (p_d->forks != NULL)
		free(p_d->forks);
	if (p_d->t != NULL)
		free(p_d->t);
}

int			print_error(int i, t_arg *arg, t_p_data *p_d)
{
	if (i == 1)
		printf("Memory allocation error\n");
	else if (i == 2)
	{
		printf("Arguments error\nplz check arguments and retry\n");
	}
	if (arg != NULL)
		free(arg);
	if (p_d != NULL)
		free_p_data(p_d);
	return (1);
}

int			set_p_data2(t_p_data *p_d, t_arg *arg)
{
	p_d->arg = arg;
	p_d->mutexes = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * arg->n_o_p);
	p_d->forks = (int *)malloc(sizeof(int) * arg->n_o_p);
	p_d->t = (pthread_t *)malloc(sizeof(pthread_t) * arg->n_o_p);
	if (p_d->mutexes == NULL || p_d->forks == NULL || p_d->t == NULL)
		return (print_error(1, arg, p_d));
	return (0);
}

int			set_p_data(t_p_data *p_d, char **argv, int argc)
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	if (arg == NULL)
		return (print_error(1, NULL, NULL));
	arg->n_o_p = ft_atoi(argv[1]);
	arg->t_t_d = ft_atoi(argv[2]) * 1000;
	arg->t_t_e = ft_atoi(argv[3]) * 1000;
	arg->t_t_s = ft_atoi(argv[4]) * 1000;
	arg->n_o_t = ft_atoi(argv[5]) * 1000;
	if (arg->n_o_p == 0 || arg->t_t_d == 0 || arg->t_t_e == 0 ||
			arg->t_t_s == 0 || argc > 5)
		return (print_error(2, arg, NULL));
	return (set_p_data2(p_d, arg));
}

int				main(int argc, char **argv)
{
	t_p_data	p_d;
	t_ph		*ph;
	int			i;

	if (set_p_data(&p_d, argv, argc))
		return (0);
	ph = (t_ph *)malloc(sizeof(t_ph) * p_d.arg->n_o_p);
	if (ph == NULL)
		return (print_error(1, p_d.arg, &p_d));
	i = 0;
	while (i < p_d.arg->n_o_p)
	{
		ph[i].p_n = i;
		ph[i].p_d = &p_d;
		i++;
	}
	philo(ph, p_d.t, p_d.mutexes);
	print_error(0, p_d.arg, &p_d);
	free(ph);
}
