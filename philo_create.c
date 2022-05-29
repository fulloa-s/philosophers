/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:10:00 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/07/22 18:15:40 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	timestamp(t_philo *philo, int c)
{
	unsigned int	tot_time;

	tot_time = mtime();
	if (c == 1)
		philo->t_meal = tot_time;
	return (tot_time - (*philo->t0));
}

void	ft_usleep(int time, t_philo *philo)
{
	unsigned int	end;

	end = mtime() + time;
	while (mtime() < end && ((*philo->isdead) == 0))
		usleep(time);
}

void	ft_createphilo(t_info *info)
{
	unsigned int	i;

	i = 0;
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->pars.n_philo);
	info->forks = malloc(sizeof(int) * (info->pars.n_philo));
	ft_initphilo_addr(info);
	ft_initforks(info);
	gettimeofday(&info->time, NULL);
	info->t0 = (info->time.tv_sec * 1000) + (info->time.tv_usec / 1000);
	while (i < info->pars.n_philo)
	{
		info->philo[i].t_meal = info->t0;
		pthread_create(&info->philo[i].thread, NULL, routine, &info->philo[i]);
		i++;
	}
}

void	ft_death(t_philo *philo)
{
	if (((mtime() - (philo->t_meal)) >= philo->ph_pars->time_die))
	{
		(*philo->isdead)++;
		pthread_mutex_lock(philo->print_ph);
		if ((*philo->isdead) == 1)
			printf("%u\t%u\t died\n", timestamp(philo, 0), philo->id_philo + 1);
		(*philo->isdead) = 2;
		pthread_mutex_unlock(philo->print_ph);
	}
	else if ((*philo->argc == 6) && philo->full == 0 && (philo->n_meals) == 0)
	{
		(*philo->all_ate)++;
		philo->full = 1;
		if ((*philo->all_ate) == (philo->ph_pars->n_philo))
		{
			(*philo->isdead) = 1;
			pthread_mutex_lock(philo->print_ph);
			printf("Done! Each philosopher eat at least %u times\n", \
			(philo->ph_pars->n_meals));
			pthread_mutex_unlock(philo->print_ph);
		}
	}
}

void	*ft_checkdeath(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while ((*philo->isdead) == 0)
	{
		pthread_mutex_lock(philo->death_ph);
		ft_death(philo);
		pthread_mutex_unlock(philo->death_ph);
		usleep(10);
	}
	return (NULL);
}
