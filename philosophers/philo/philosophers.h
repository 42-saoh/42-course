/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:15:47 by saoh              #+#    #+#             */
/*   Updated: 2021/07/01 17:38:44 by saoh             ###   ########.fr       */
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

typedef struct		s_arg
{
	int				n_o_p;
	int				t_t_d;
	int				t_t_e;
	int				t_t_s;
	int				n_o_t;
}					t_arg;

typedef struct		s_p_data
{
	struct timeval	f_tv;
	struct s_arg	*arg;
	int				*forks;
	pthread_mutex_t	*mutexes;
	pthread_t		*t;
	int				p_d_f;
}					t_p_data;

typedef struct		s_ph
{
	struct s_p_data	*p_d;
	int				p_n;
	struct timeval	tv;
}					t_ph;

int					ft_atoi(char *str);
void				philo(t_ph *ph, pthread_t *t, pthread_mutex_t *mutexes);

#endif
