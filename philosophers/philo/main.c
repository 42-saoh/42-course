/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:28:46 by saoh              #+#    #+#             */
/*   Updated: 2021/06/29 16:20:58 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int			get_argu(t_ph *ph, char **argv)
{
	ph->n_o_p = ft_atoi(argv[1]);
	ph->t_t_d = ft_atoi(argv[2]);
	ph->t_t_e = ft_atoi(argv[3]);
	ph->t_t_s = ft_atoi(argv[4]);
	ph->n_o_t = ft_atoi(argv[5]);
	if (ph->n_o_p == -1 || ph->t_t_d == -1 || ph->t_t_e == -1 ||
			ph->t_t_s == -1)
	{
		printf("Arguments error\nplz check arguments and retry\n");
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_ph	ph;

	if (get_argu(&ph, argv))
		return (0);
	philo(&ph);
}
