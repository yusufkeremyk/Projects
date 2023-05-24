/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalbayra < yalbayra@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:46:24 by yalbayra          #+#    #+#             */
/*   Updated: 2023/05/23 21:46:24 by yalbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//char olarak girilen diziyi inte cevirir.
int	ft_atoi(const char *str)
{
	long int	res;
	int			a;

	a = 1;
	res = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			a *= -1;
	str++;
	}
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0') * a;
		if (res > 2147483647)
			return (-1);
		if (res < -2147483648)
			return (0);
		str++;
	}
	return (res);
}

/* int	main(void)
{
	char	a[] = "   	-1234";

	printf("%d", ft_atoi(a));
} */