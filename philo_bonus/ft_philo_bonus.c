/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:15:07 by ozahidi           #+#    #+#             */
/*   Updated: 2024/06/01 20:27:41 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	if (ac != 5 && ac != 6)
	{
		printf("to run <<./philo_bonus>> flow next step:\n");
		printf("./phile [number_of_philosophers] ");
		printf("[time_to_die] [time_to_eat] [time_to_sleep]\n");
		printf("You can add [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	else
	{
		philo = NULL;
		if (check_arg(av, ac) == 1)
			return (printf("Error : incorrect argument\n"), 1);
		data = create_data(av, ac);
		philo = create_table(data, av, ac);
		create_processes(philo);
	}
}
