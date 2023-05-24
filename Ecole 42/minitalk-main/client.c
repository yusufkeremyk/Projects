/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:30:16 by yaktas            #+#    #+#             */
/*   Updated: 2023/05/23 21:54:11 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	a;

	a = 0;
	while (*str)
	{
		a = a * 10 + (*str - '0');
		str++;
	}
	return (a);
}

void	ft_sendbit(int pid, char *av)
{
	int	i;

	while (*av)
	{
		i = 8;
		while (i--)
		{
			if ((*av >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		av++;
	}
}

int	main(int ac, char **av)
{
	if (ac > 3)
		write(1, "Too many arguments\n", 20);
	else if (ac < 3)
		write(1, "Missing arguments\n", 18);
	else
		ft_sendbit(ft_atoi(av[1]), av[2]);
	return (0);
}
