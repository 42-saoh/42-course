/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:15:47 by saoh              #+#    #+#             */
/*   Updated: 2021/06/29 16:37:31 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct		s_ph
{
	int				n_o_p;
	int				t_t_d;
	int				t_t_e;
	int				t_t_s;
	int				*forks;
	pthread_mutex_t	*mutexes;
	pthread_t		*t;
	int				n_o_t;
}					t_ph;

int					ft_atoi(char *str);
void				philo(t_ph *ph);

#endif
