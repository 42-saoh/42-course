/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:28:46 by saoh              #+#    #+#             */
/*   Updated: 2021/07/17 15:51:31 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	print_error(int i)
{
	if (i == 1)
		printf("Memory allocation error\n");
	else if (i == 2)
		printf("Arguments error\nplz check arguments and retry\n");
	else if (i == 3)
		printf("Semaphore error\nplz Semaphore was previously created\nplz check and retry\n");
	exit(0);
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

static void	set_p_data(t_p_data *p_d, char **argv, int argc)
{
	p_d->n_o_p = ft_atoi(argv[1]);
	p_d->t_t_d = ft_atoi(argv[2]) * 1000;
	p_d->t_t_e = ft_atoi(argv[3]) * 1000;
	p_d->t_t_s = ft_atoi(argv[4]) * 1000;
	p_d->n_o_t = ft_atoi(argv[5]);
	p_d->die_flag = 0;
	if (!p_d->n_o_p || !p_d->t_t_d || !p_d->t_t_e || !p_d->t_t_s || argc > 6)
		print_error(2);
	p_d->forks = sem_open("forks", O_EXCL | O_CREAT, 0644, p_d->n_o_p);
	if (p_d->forks == SEM_FAILED)
	{
		sema_exit(NULL, p_d, 0);
		print_error(3);
	}
}

static void	get_ph(t_ph *ph, t_p_data *p_d)
{
	int		i;
	char	*name;

	i = 0;
	while (i < p_d->n_o_p)
	{
		ph[i].p_n = i;
		ph[i].p_d = p_d;
		ph[i].eat_c = 0;
		ph[i].eat_flag = 0;
		name = get_name(i);
		ph[i].eat_end = sem_open(name, O_EXCL | O_CREAT, 0644, 1);
		if (ph[i].eat_end == SEM_FAILED)
		{
			free(name);
			sema_exit(ph, p_d, i + 1);
			free(ph);
			print_error(3);
		}
		sem_wait(ph[i].eat_end);
		free(name);
		name = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_p_data	p_d;
	t_ph		*ph;

	set_p_data(&p_d, argv, argc);
	ph = (t_ph *)malloc(sizeof(t_ph) * p_d.n_o_p);
	if (!ph)
	{
		sema_exit(ph, &p_d, 0);
		print_error(1);
	}
	get_ph(ph, &p_d);
	philo(ph);
	sema_exit(ph, &p_d, p_d.n_o_p);
	free(ph);
	return (0);
}
