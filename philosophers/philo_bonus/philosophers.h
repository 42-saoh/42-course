/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:15:47 by saoh              #+#    #+#             */
/*   Updated: 2021/09/20 14:05:32 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>

typedef struct s_p_data
{
	int				n_o_p;
	int				t_t_d;
	int				t_t_e;
	int				t_t_s;
	int				n_o_t;
	int				die_flag;
	long			first_time;
	pid_t			p_moniter;
	sem_t			*forks;
	sem_t			*end;
}t_p_data;

typedef struct s_ph
{
	int				p_n;
	int				eat_flag;
	int				eat_c;
	pid_t			p_pid;
	sem_t			*eat_end;
	long			eat_time;
	struct s_p_data	*p_d;
}t_ph;

void				philo(t_ph *ph);
void				each_philo(t_ph *ph);
long				get_time(void);
void				print_state(long time, t_ph *ph, char *s);
void				sema_exit(t_ph *ph, t_p_data *p_d, int num);
void				sema_error(void);
void				*philoso_moniter(void *arg);
void				eat_moniter(t_ph *ph);
char				*get_name(int n);

#endif
