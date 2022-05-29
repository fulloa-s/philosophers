/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:35:11 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/07/22 18:36:33 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdint.h>
# include <limits.h>
# include <sys/time.h>

# define ERR_PARS "Parsing Error\n"

typedef struct s_pars
{
	unsigned int		n_philo;
	unsigned int		time_die;
	unsigned int		time_eat;
	unsigned int		time_sleep;
	unsigned int		n_meals;
}t_pars;

typedef struct s_philo
{
	t_pars				*ph_pars;
	pthread_t			thread;
	struct timeval		time_ph;
	pthread_mutex_t		*rfork_m;
	pthread_mutex_t		*lfork_m;
	pthread_mutex_t		*print_ph;
	pthread_mutex_t		*death_ph;
	unsigned int		id_philo;
	unsigned int		n_meals;
	unsigned int		*t0;
	unsigned int		t_meal;
	unsigned int		*all_ate;
	int					*fork_r;
	int					*fork_l;
	int					full;
	int					*isdead;
	int					*argc;		
}t_philo;

typedef struct s_info
{
	t_pars				pars;
	t_philo				*philo;
	struct timeval		time;
	pthread_mutex_t		*forks_m;
	pthread_mutex_t		print;
	pthread_mutex_t		death_m;
	unsigned int		t0;
	unsigned int		all_ate;
	int					*forks;
	int					isdead;
	int					*argc;
}t_info;

unsigned int	timestamp(t_philo *philo, int c);
void			ft_usleep(int time, t_philo *philo);
void			ft_createphilo(t_info *info);
void			ft_death(t_philo *philo);
void			*ft_checkdeath(void *arg);
void			ft_initphilo_addr(t_info *info);
void			ft_initforks(t_info *info);
void			ft_checkline(int argc, char **argv);
int				ft_parsing(int argc, char **argv, t_pars *pars);
void			ft_pars_init(t_pars *pars);
void			ft_tookfork(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo *philo);
void			ft_think(t_philo *philo);
void			*routine(void *arg);
void			ft_error(char *str);
int				ft_isdigit(int c);
unsigned int	ft_atoinumb(const char *str, unsigned int i);
unsigned int	ft_atou(const char *str);
unsigned int	mtime(void);

#endif