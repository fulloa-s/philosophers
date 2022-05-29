/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:59:22 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/07/22 16:41:41 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_checkline(int argc, char **argv)
{
	int	i;
	int	ac;

	i = 0;
	ac = argc - 1;
	while (ac)
	{
		i = 0;
		while (argv[ac][i])
		{
			if (!ft_isdigit(argv[ac][i]))
				ft_error(ERR_PARS);
			i++;
		}
		ac--;
	}
}

int	ft_parsing(int argc, char **argv, t_pars *pars)
{
	ft_pars_init(pars);
	ft_checkline(argc, argv);
	pars->n_philo = ft_atou(argv[1]);
	pars->time_die = ft_atou(argv[2]);
	pars->time_eat = ft_atou(argv[3]);
	pars->time_sleep = ft_atou(argv[4]);
	pars->n_meals = ft_atou(argv[5]);
	return (0);
}

void	ft_pars_init(t_pars *pars)
{
	pars->n_philo = 0;
	pars->time_die = 0;
	pars->time_eat = 0;
	pars->time_sleep = 0;
	pars->n_meals = 0;
}
