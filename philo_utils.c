/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:46:09 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/07/22 18:07:18 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *str)
{
	printf("%s", str);
	exit(1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

unsigned int	ft_atoinumb(const char *str, unsigned int i)
{
	unsigned long	number;

	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + str[i] - 48;
		i++;
	}
	if (number > UINT_MAX)
		ft_error(ERR_PARS);
	return ((unsigned int)number);
}

unsigned int	ft_atou(const char *str)
{
	unsigned int		i;
	unsigned int		res;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	res = ft_atoinumb(str, i);
	return (res);
}

unsigned int	mtime(void)
{
	struct timeval	tv;
	unsigned int	tot_time;

	gettimeofday(&tv, NULL);
	tot_time = tv.tv_sec * 1000;
	tot_time += tv.tv_usec / 1000;
	return (tot_time);
}
