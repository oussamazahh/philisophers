/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:34:46 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/26 21:07:26 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_data	*create_data(char **av, int ac)
{
	int i;
	t_data *data;

	i = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->number_of_philo = ft_atoi(av[1]);
	data->number_of_fork = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->time = get_current_time();
	if (ac == 6)
		data->nt_eat = ft_atoi(av[5]);
	else
		data->nt_eat = -1;
	data->kill = 0;
	data->id_kill = 0;
	sem_unlink("check");
	data->check = sem_open("check", O_CREAT, 0644, 1);
	sem_unlink("forks");
	data->forks = sem_open("forks", O_CREAT, 0644, data->number_of_fork);
	return (data);
}
