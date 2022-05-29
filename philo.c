/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:02:30 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/07/22 16:39:20 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info			info;
	unsigned int	i;

	i = 0;
	if (argc > 1 && argc < 7)
		ft_parsing(argc, argv, &info.pars);
	else
		ft_error(ERR_PARS);
	info.argc = &argc;
	ft_createphilo(&info);
	while (i < info.pars.n_philo)
	{
		pthread_join(info.philo[i].thread, NULL);
		i++;
	}
	pthread_mutex_unlock(&info.print);
	pthread_mutex_destroy(&info.print);
	free(info.philo);
	free(info.forks_m);
	free(info.forks);
}
