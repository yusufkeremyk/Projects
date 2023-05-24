/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:08:34 by yaktas            #+#    #+#             */
/*   Updated: 2023/05/23 21:54:09 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_intlen(int a)
{
	int	i;

	i = 0;
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

char	*ft_putnbr(int nbr)
{
	char	*m;
	int		a;

	a = ft_intlen(nbr);
	m = (char *)malloc(sizeof(char) * (a + 1));
	m[a] = '\0';
	while (a > 0)
	{
		m[a - 1] = nbr % 10 + '0';
		nbr /= 10;
		a--;
	}
	return (m);
}

void	ft_handle(int sig)
{
	static int	a = 128;
	static char	c;

	if (sig == SIGUSR1)
		c += a;
	a = a / 2;
	if (a == 0)
	{
		write(1, &c, 1);
		a = 128;
		c = 0;
	}
}

int	main(void)
{
	write(1, "PID:", 4);
	write(1, ft_putnbr(getpid()), ft_intlen(getpid()));
	write(1, "\n", 1);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	while (1)
		pause();
	return (0);
}
