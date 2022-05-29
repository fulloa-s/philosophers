/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:15:55 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/07/22 18:15:40 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_initphilo_addr(t_info *info)
{
	unsigned int	i;

	i = 0;
	while (i < info->pars.n_philo)
	{
		info->philo[i].id_philo = i;
		info->philo[i].argc = info->argc;
		info->philo[i].ph_pars = &info->pars;
		info->philo[i].print_ph = &info->print;
		info->philo[i].t0 = &info->t0;
		info->philo[i].n_meals = info->pars.n_meals;
		info->forks[i] = 0;
		info->philo[i].isdead = &info->isdead;
		info->philo[i].death_ph = &info->death_m;
		info->philo[i].all_ate = &info->all_ate;
		info->philo[i].full = 0;
		i++;
	}
	info->isdead = 0;
	info->all_ate = 0;
}

void	ft_initforks(t_info *info)
{
	unsigned int	i;

	i = 0;
	info->forks_m = malloc(sizeof(pthread_mutex_t) * (info->pars.n_philo));
	while (i < info->pars.n_philo)
	{
		pthread_mutex_init(&info->forks_m[i], NULL);
		info->philo[i].lfork_m = &info->forks_m[i];
		if (i != (info->pars.n_philo - 1))
			info->philo[i].rfork_m = &info->forks_m[(i + 1)];
		else
			info->philo[i].rfork_m = &info->forks_m[0];
		info->philo[i].fork_l = &info->forks[i];
		if (i != (info->pars.n_philo - 1))
			info->philo[i].fork_r = &info->forks[i + 1];
		else
			info->philo[i].fork_r = &info->forks[0];
		i++;
	}
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->death_m, NULL);
}
