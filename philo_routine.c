/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:07:55 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/07/22 18:15:40 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_tookfork(t_philo *philo)
{
	pthread_mutex_lock(philo->print_ph);
	if ((*philo->isdead) == 0)
		printf("%u\t%u\thas taken a fork\n", timestamp(philo, 0), \
		philo->id_philo + 1);
	pthread_mutex_unlock(philo->print_ph);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->print_ph);
	if ((*philo->argc) == 6 && philo->n_meals > 0)
		philo->n_meals--;
	if ((*philo->isdead) == 0)
		printf("%u\t%u\tis eating\n", timestamp(philo, 1), philo->id_philo + 1);
	pthread_mutex_unlock(philo->print_ph);
	ft_usleep(philo->ph_pars->time_eat, philo);
	*(philo->fork_l) = 0;
	pthread_mutex_unlock(philo->lfork_m);
	*(philo->fork_r) = 0;
	pthread_mutex_unlock(philo->rfork_m);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->print_ph);
	if ((*philo->isdead) == 0)
		printf("%u\t%u\tis sleeping\n", timestamp(philo, 0), philo->id_philo + 1);
	pthread_mutex_unlock(philo->print_ph);
	ft_usleep(philo->ph_pars->time_sleep, philo);
}

void	ft_think(t_philo *philo)
{
	pthread_mutex_lock(philo->print_ph);
	if ((*philo->isdead) == 0)
		printf("%u\t%u\tis thinking\n", timestamp(philo, 0), philo->id_philo + 1);
	pthread_mutex_unlock(philo->print_ph);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	pthread_t	checker;

	philo = (t_philo *)arg;
	pthread_create(&checker, NULL, ft_checkdeath, philo);
	if (philo->id_philo % 2 != 0)
		ft_usleep(philo->ph_pars->time_eat, philo);
	while ((*philo->isdead) == 0)
	{
		pthread_mutex_lock(philo->lfork_m);
		*(philo->fork_l) = 1;
		ft_tookfork(philo);
		if (philo->ph_pars->n_philo == 1)
			break ;
		pthread_mutex_lock(philo->rfork_m);
		*(philo->fork_r) = 1;
		ft_tookfork(philo);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	pthread_join(checker, NULL);
	return (NULL);
}
