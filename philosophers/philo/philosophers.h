/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:15:47 by saoh              #+#    #+#             */
/*   Updated: 2021/09/11 15:12:51 by saoh             ###   ########.fr       */
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

typedef struct s_p_data
{
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	msg_mutex;
	pthread_mutex_t	start_mutex;
	int				n_o_p;
	int				t_t_d;
	int				t_t_e;
	int				t_t_s;
	int				n_o_t;
	int				die_flag;
	long			first_time;
	pthread_mutex_t	*mutexes;
}t_p_data;

typedef struct s_ph
{
	int				p_n;
	int				eat_c;
	long			eat_time;
	long			start_sec;
	struct s_p_data	*p_d;
	int				eat_flag;
}t_ph;

void				philo(t_ph *ph);
void				oddphilo(t_ph *ph);
long				get_time(void);
void				print_state(long time, t_ph *ph, char *s);
void				*philoso_moniter(void *arg);
void				*eat_moniter(void *arg);

#endif